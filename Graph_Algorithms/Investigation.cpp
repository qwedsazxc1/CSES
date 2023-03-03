#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MOD ((long long)1e9 + 7)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        from--; to--;
        graph[from].push_back(make_pair(to, weight));
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, 1e18);
    vector<pair<int, int>> min_and_max_amount(n, make_pair(n, 0));
    vector<long long> combination(n, 0);
    combination[0] = 1;
    min_and_max_amount[0].first = 0;
    min_and_max_amount[0].second = 0;
    dist[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()){
        pair<long long, int> front = pq.top();
        pq.pop();
        if (front.first > dist[front.second])
            continue;
        for (auto p: graph[front.second]){
            if (dist[p.first] > p.second + dist[front.second]){
                dist[p.first] = p.second + dist[front.second];
                min_and_max_amount[p.first].first = min_and_max_amount[front.second].first + 1;
                min_and_max_amount[p.first].second = min_and_max_amount[front.second].second + 1;
                combination[p.first] = combination[front.second];
                pq.push(make_pair(dist[p.first], p.first));
            }
            else if (dist[p.first] == p.second + dist[front.second]){
                min_and_max_amount[p.first].first;
                combination[p.first] += combination[front.second];
                combination[p.first] %= MOD;
                min_and_max_amount[p.first].first = min(min_and_max_amount[p.first].first, min_and_max_amount[front.second].first + 1);
                min_and_max_amount[p.first].second = max(min_and_max_amount[p.first].second, min_and_max_amount[front.second].second + 1);
            }
        }
    }
    cout << dist[n - 1] << " " << combination[n - 1] << " " << min_and_max_amount[n - 1].first << " " << min_and_max_amount[n - 1].second << "\n";
    return 0;
}