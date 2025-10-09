#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct union_find{
    vector<ll> pa_sz;
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

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, pair<int, int>>> edges;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--; b--;
        edges.push_back({w, {a, b}});
    }
    sort(edges.rbegin(), edges.rend());
    union_find dsu(n);
    for (auto [w, e] : edges){
        auto [a, b] = e;
        a = dsu.find(a);
        b = dsu.find(b);
        ans += dsu.pa_sz[a] * dsu.pa_sz[b] * w;
        dsu.merge(a, b);
    }
    cout << ans << "\n";
}