#include <bits/stdc++.h>

using namespace std;

vector<int> have_cycle;
struct union_find{
    vector<int> pa_sz;
    union_find(int n): pa_sz(n, -1) {}
    int find(int x){
        if (pa_sz[x] < 0)
            return x;
        return pa_sz[x] = find(pa_sz[x]);
    }
    int merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b)
            return 0;
        if (pa_sz[a] > pa_sz[b])
            swap(a, b);
        pa_sz[a] += pa_sz[b];
        pa_sz[b] = a;
        have_cycle[a] |= have_cycle[b];
        return 1;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> vis(n);
    have_cycle.assign(n, 0);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    auto dfs = [&](auto &self, int cur) -> void {
        vis[cur] = 1;
        for (auto &nxt: graph[cur]){
            if (vis[nxt] == 1){
                have_cycle[cur] = 1;
                continue;
            }
            if (vis[nxt] == 0)
                self(self, nxt);
        }
        vis[cur] = 2;
    };
    for (int i = 0; i < n; i++){
        if (!vis[i])
            dfs(dfs, i);
    }
    union_find dsu(n);
    for (int i = 0; i < n; i++){
        for (auto next: graph[i])
            dsu.merge(i, next);
    }
    int ans = n;
    for (int i = 0; i < n; i++){
        if (dsu.pa_sz[i] < 0 && !have_cycle[i]){
            ans--;
        }
    }
    cout << ans << "\n";
}