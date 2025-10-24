#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    unordered_map<int, set<int>> m;
    m.reserve(2048);
    m.max_load_factor(0.25);
    for (int i = 0; i < n; i++){
        m[arr[i]].insert(i);
    }
    vector<int> tree(n << 2, INF);
    auto update = [&](auto &self, int cur, int l, int r, int k, int x) -> void {
        if (k < l || k > r)
            return;
        if (l == r){
            tree[cur] = x;
            return;
        }
        int mid = (l + r) / 2;
        self(self, cur * 2 + 1, l, mid, k, x);
        self(self, cur * 2 + 2, mid + 1, r, k, x);
        tree[cur] = min(tree[cur * 2 + 1], tree[cur * 2 + 2]);
    };
    auto query = [&](auto &self, int cur, int l, int r, int ql, int qr) -> int {
        if (qr < l || ql > r)
            return INF;
        if (ql <= l && r <= qr)
            return tree[cur];
        int mid = (l + r) / 2;
        return min(self(self, cur * 2 + 1, l, mid, ql, qr),
                   self(self, cur * 2 + 2, mid + 1, r, ql, qr));
    };
    for (int i = 0; i < n; i++){
        auto it = m[arr[i]].upper_bound(i);
        if (it == m[arr[i]].end())
            update(update, 0, 0, n - 1, i, n);
        else
            update(update, 0, 0, n - 1, i, *it);
    }
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int k, x;
            cin >> k >> x;
            k--;
            auto it = m[arr[k]].find(k);
            if (it != m[arr[k]].begin()){
                auto pre = prev(it);
                if (it == m[arr[k]].end() || next(it) == m[arr[k]].end()){
                    update(update, 0, 0, n - 1, *pre, n);
                }
                else{
                    auto nxt = next(it);
                    update(update, 0, 0, n - 1, *pre, *nxt);
                }
            }
            m[arr[k]].erase(it);
            arr[k] = x;
            m[arr[k]].insert(k);
            it = m[arr[k]].find(k);
            if (it != m[arr[k]].begin()){
                auto pre = prev(it);
                update(update, 0, 0, n - 1, *pre, k);
            }
            auto nxt = next(it);
            if (nxt == m[arr[k]].end()){
                update(update, 0, 0, n - 1, k, n);
            }
            else{
                update(update, 0, 0, n - 1, k, *nxt);
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            int res = query(query, 0, 0, n - 1, l, r);
            if (res <= r)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
    return 0;
}