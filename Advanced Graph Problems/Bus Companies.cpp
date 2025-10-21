#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> cost(m);
    for (int i = 0; i < m; i++)
        cin >> cost[i];
    vector<vector<int>> com(m);
    vector<vector<int>> city(n);
    for (int i = 0; i < m; i++){
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++){
            int x;
            cin >> x;
            com[i].push_back(x - 1);
            city[x - 1].push_back(i);
        }
    }
    vector<ll> dist(n, INF);
    vector<bool> used(m, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()){
        auto [d, cur] = pq.top();
        pq.pop();
        if (dist[cur] != INF)
            continue;
        dist[cur] = d;
        for (auto c: city[cur]){
            if (used[c])
                continue;
            used[c] = true;
            for (auto v: com[c]){
                pq.push({d + cost[c], v});
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << dist[i] << " \n"[i == n - 1];
    }
    return 0;
}