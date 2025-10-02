#include <bits/stdc++.h>

using namespace std;

struct edge{
    int to, prev, cap;
};

int main(){
    int n;
    cin >> n;
    vector<vector<edge>> g(2 * n + 2);
    auto add_edge = [&](int u, int v, int cap){
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    };
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        add_edge(0, i + 1, x);
        sum1 += x;
    }
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        add_edge(n + 1 + i, 2 * n + 1, x);
        sum2 += x;
    }
    if (sum1 != sum2){
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            add_edge(i + 1, n + 1 + j, 1);
        }
    }
    vector<int> level(2 * n + 2);
    auto bfs = [&](){
        fill(level.begin(), level.end(), -1);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()){
            auto [u, d] = q.front();
            q.pop();
            if (level[u] != -1)
                continue;
            level[u] = d;
            for (auto &e : g[u]){
                if (e.cap > 0){
                    q.push({e.to, d + 1});
                }
            }
        }
        return level[2 * n + 1] != -1;
    };

    auto dfs = [&](auto self, int cur, int flow) -> int {
        if (cur == 2 * n + 1)
            return flow;
        for (auto &e : g[cur]){
            if (e.cap > 0 && level[e.to] == level[cur] + 1){
                int res = self(self, e.to, min(flow, e.cap));
                if (res > 0){
                    e.cap -= res;
                    g[e.to][e.prev].cap += res;
                    return res;
                }
            }
        }
        return 0;
    };

    auto dinic = [&](){
        int flow = 0;
        while (1){
            if (!bfs())
                break;
            int res;
            while (res = dfs(dfs, 0, INT_MAX)){
                flow += res;
            }
        }
        return flow;
    };
    int res = dinic();
    if (res != sum1){
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (auto &e : g[i + 1]){
            if (e.to != 0 && e.cap == 0){
                ans[i][e.to - n - 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << (ans[i][j] ? 'X' : '.');
        }
        cout << "\n";
    }
}