#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> dist(n, -1);
    auto bfs = [&](){
        queue<pair<int, ll>> q;
        for (int i = 0; i < n; i++){
            if (arr[i]){
                q.push({i, 0});
            }
        }
        while (!q.empty()){
            auto [cur, d] = q.front();
            q.pop();
            if (dist[cur] != -1)
                continue;
            dist[cur] = d;
            for (auto &next : graph[cur]){
                q.push({next, d + 1});
            }
        }
    };
    bfs();
    vector<int> pa(n - 1), dep(n), sz(n, 1), heavy(n, -1), head(n), id(n);
    auto dfs1 = [&](auto &self, int cur, int prev) -> void {
        pa[cur] = prev;
        for (auto &next : graph[cur]){
            if (next == prev)
                continue;
            dep[next] = dep[cur] + 1;
            self(self, next, cur);
            sz[cur] += sz[next];
            if (heavy[cur] == -1 || sz[next] > sz[heavy[cur]]){
                heavy[cur] = next;
            }
        }
    };
    int cur_id = 0;
    auto dfs2 = [&](auto &self, int cur, int prev, int h) -> void {
        head[cur] = h;
        id[cur] = cur_id++;
        if (heavy[cur] != -1){
            self(self, heavy[cur], cur, h);
        }
        for (auto &next : graph[cur]){
            if (next == prev || next == heavy[cur])
                continue;
            self(self, next, cur, next);
        }
    };
    dfs1(dfs1, 0, 0);
    dfs2(dfs2, 0, 0, 0);
    vector<ll> tree(n << 2, INF);
    auto update = [&](auto &self, int cur, int l, int r, int k, ll x){
        if (k > r || k < l)
            return;
        if (l == r){
            tree[cur] = min(tree[cur], x);
            return;
        }
        int mid = (l + r) / 2;
        self(self, cur * 2 + 1, l, mid, k, x);
        self(self, cur * 2 + 2, mid + 1, r, k, x);
        tree[cur] = min(tree[cur * 2 + 1], tree[cur * 2 + 2]);
    };
    auto query = [&](auto &self, int cur, int l, int r, int ql, int qr) -> ll {
        if (ql > r || qr < l)
            return INF;
        if (l >= ql && r <= qr)
            return tree[cur];
        int mid = (l + r) / 2;
        return min(self(self, cur * 2 + 1, l, mid, ql, qr), self(self, cur * 2 + 2, mid + 1, r, ql, qr));
    };
    for (int i = 0; i < n; i++){
        update(update, 0, 0, n - 1, id[i], dist[i]);
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        ll temp = INF;
        ll ans = 0;
        while (head[a] != head[b]){
            if (dep[head[a]] < dep[head[b]])
                swap(a, b);
            temp = min(temp, query(query, 0, 0, n - 1, id[head[a]], id[a]));
            ans += (dep[a] - dep[head[a]] + 1);
            a = pa[head[a]];
        }
        if (dep[a] > dep[b])
            swap(a, b);
        ans += (dep[b] - dep[a]);
        temp = min(temp, query(query, 0, 0, n - 1, id[a], id[b]));
        cout << ans + temp * 2 << "\n";
    }
}