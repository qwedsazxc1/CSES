#include <bits/stdc++.h>

using namespace std;

struct union_and_find{
    vector<int> pa_sz;
    union_and_find(int n) : pa_sz(n, -1) {}
    int find(int a){
        if (pa_sz[a] < 0) return a;
        return pa_sz[a] = find(pa_sz[a]);
    }
    int merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b) return 0;
        if (pa_sz[a] > pa_sz[b]) swap(a, b);
        pa_sz[a] += pa_sz[b];
        pa_sz[b] = a;
        return 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<pair<int, int>, int>>> edges;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[w].push_back({{u, v}, i});
    }
    union_and_find dsu(n);
    vector<int> ans(m, 0);
    for (auto &[w, arr] : edges){
        for (auto &[e, i] : arr){
            int u = e.first, v = e.second;
            if (dsu.find(u) != dsu.find(v)) 
                ans[i] = 1;
        }
        for (auto &[e, i] : arr){
            int u = e.first, v = e.second;
            dsu.merge(u, v);
        }
    }
    for (int i = 0; i < m; i++)
        cout << (ans[i] ? "YES\n" : "NO\n");
    return 0;
}