#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n);
    set<int> shops;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        x--;
        shops.insert(x);
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    map<int, int> dist;
    for (auto s : shops){
        dist[s] = INF;
    }
    vector<pair<int, int>> dis(n, {-1, INF});
    queue<pair<int, pair<int, int>>> q;
    for (auto s : shops){
        q.push({0, {s, s}});
    }
    while (!q.empty()){
        auto [d, p] = q.front();
        auto [cur, s] = p;
        q.pop();
        if (dis[cur].second != INF){
            if (s != dis[cur].first){
                dist[dis[cur].first] = min(dist[dis[cur].first], d + dis[cur].second);
                dist[s] = min(dist[s], d + dis[cur].second);
            }
            continue;
        }
        dis[cur] = {s, d};
        for (auto v : graph[cur]){
            q.push({d + 1, {v, s}});
        }
    }
    for (int i = 0; i < n; i++){
        int res;
        if (shops.find(i) != shops.end()){
            res = dist[i];
        } 
        else{
            res = dis[i].second;
        }
        if (res == INF)
            res = -1;
        cout << res << " \n"[i == n - 1];
    }
}