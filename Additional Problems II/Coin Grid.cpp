#include <bits/stdc++.h>

using namespace std;

struct edge{
    int v, rev, cap;
};

int main(){
    int n;
    cin >> n;
    vector<vector<edge>> graph(2 * n + 2);

    auto add_edge = [&](int u, int v, int cap){
        graph[u].push_back({v, (int)graph[v].size(), cap});
        graph[v].push_back({u, (int)graph[u].size() - 1, 0});
    };
    for (int i = 0; i < n; i++){
        add_edge(0, i + 1, 1);
        add_edge(i + n + 1, 2 * n + 1, 1);
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            if (c == 'o'){
                add_edge(i + 1, j + n + 1, 1);
            }
        }
    }
    vector<int> level(2 * n + 2);
    auto bfs = [&]() -> int {
        fill(level.begin(), level.end(), -1);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()){
            auto [cur, d] = q.front();
            q.pop();
            if (level[cur] != -1)
                continue;
            level[cur] = d;
            for (auto &e : graph[cur]){
                if (e.cap > 0){
                    q.push({e.v, d + 1});
                }
            }
        }
        return level[2 * n + 1] != -1;
    };
    auto dfs = [&](auto &self, int cur, int flow) -> int {
        if (cur == 2 * n + 1)
            return flow;
        for (auto &e : graph[cur]){
            if (e.cap > 0 && level[e.v] == level[cur] + 1){
                int min_flow = self(self, e.v, min(flow, e.cap));
                if (min_flow > 0){
                    e.cap -= min_flow;
                    graph[e.v][e.rev].cap += min_flow;
                    return min_flow;
                }
            }
        }
        return 0;
    };
    int max_flow = 0;
    auto dinic = [&]() {
        while (1){
            int res = bfs();
            if (!res)
                break;
            int flow;
            while (flow = dfs(dfs, 0, n)){
                max_flow += flow;
            }
        }
    };
    dinic();
    cout << max_flow << "\n";
    for (int i = 1; i <= n; i++){
        if (level[i] < 0){
            cout << "1 " << i << "\n";
        }
        if (level[i + n] >= 0){
            cout << "2 " << i << "\n";
        }
    }
}