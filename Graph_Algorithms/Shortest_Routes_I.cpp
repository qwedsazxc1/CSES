#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }
    vector<long long> dist(n, 1e18);
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()){
        pair<long long, int> current = pq.top();
        pq.pop();
        if (current.first > dist[current.second])
            continue;
        for (pair<int, int> next : adj[current.second]){
            if (dist[next.first] > dist[current.second] + next.second){
                dist[next.first] = dist[current.second] + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
        
    }

    for (int i = 0; i < n; i++){
        if (dist[i] == 1e18)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}