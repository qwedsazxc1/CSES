#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(2 * n);
    auto add_edge = [&](int u, int v){
        graph[2 * u].push_back(2 * v + 1);
        graph[2 * v + 1].push_back(2 * u);
        graph[2 * v].push_back(2 * u + 1);
        graph[2 * u + 1].push_back(2 * v);
    };
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        add_edge(u, v);
    }
    vector<vector<int>> dis(n);
    auto bfs = [&](int s){
        vector<int> res(2 * n, -1);
        res[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int nxt : graph[cur]){
                if (res[nxt] == -1){
                    res[nxt] = res[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return res;
    };
    for (int i = 0; i < n; i++){
        dis[i] = bfs(2 * i);
    }
    while (q--){
        int u, v, k;
        cin >> u >> v >> k;
        u--; v--;
        if (k % 2){
            if (dis[u][2 * v + 1] != -1 && dis[u][2 * v + 1] <= k)
                cout << "YES\n";
            else
                cout << "NO\n";
            
        }
        else{
            if (dis[u][2 * v] != -1 && dis[u][2 * v] <= k)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}