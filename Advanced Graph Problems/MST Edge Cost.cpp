#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct union_find{
    vector<int> pa_sz;
    union_find(int n) : pa_sz(n, -1) {}
    int find(int a){
        if (pa_sz[a] < 0)
            return a;
        return pa_sz[a] = find(pa_sz[a]);
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
        return 1;
    }
};

struct edge{
    int u, v;
    ll w, idx;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
        edges[i].idx = i;
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });
    ll res = 0;
    union_find dsu(n);
    vector<vector<pii>> graph(n);
    for (auto &e : edges){
        if (dsu.merge(e.u, e.v)){
            res += e.w;
            graph[e.u].push_back({e.v, e.w});
            graph[e.v].push_back({e.u, e.w});
        }
    }
    vector<int> depth(n);
    vector<vector<int>> parent(n, vector<int>(20, 0));
    vector<vector<ll>> maxv(n, vector<ll>(20, 0));
    auto dfs = [&](auto &self, int cur, int prev, int d) -> void {
        depth[cur] = d;
        parent[cur][0] = prev;
        for (auto &[next, w] : graph[cur]){
            if (next != prev){
                maxv[next][0] = w;
                self(self, next, cur, d + 1);
            }
        }
    };
    dfs(dfs, 0, 0, 0);
    for (int i = 1; i < 20; i++){
        for (int j = 0; j < n; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
            maxv[j][i] = max(maxv[j][i - 1], maxv[parent[j][i - 1]][i - 1]);
        }
    }
    auto LCA = [&](int a, int b) -> ll {
        if (depth[a] < depth[b])
            swap(a, b);
        ll res = 0;
        ll diff = depth[a] - depth[b];
        for (int i = 0; i < 20; i++){
            if (diff & (1 << i)){
                res = max(res, maxv[a][i]);
                a = parent[a][i];
            }
        }
        if (a == b)
            return res;
        for (int i = 19; i >= 0; i--){
            if (parent[a][i] != parent[b][i]){
                res = max(res, max(maxv[a][i], maxv[b][i]));
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        res = max(res, max(maxv[a][0], maxv[b][0]));
        return res;
    };
    vector<ll> ans(m);
    for (int i = 0; i < m; i++){
        ans[edges[i].idx] = res - LCA(edges[i].u, edges[i].v) + edges[i].w;
    }
    for (int i = 0; i < m; i++){
        cout << ans[i] << " \n"[i == m - 1];
    }

}