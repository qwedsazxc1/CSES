#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> id;
    int idx = 0;
    for (int i = 0; i < n; i++){
        id[arr[i]];
    }
    for (auto &[_, v] : id)
        v = ++idx;
    for (int i = 0; i < n; i++){
        arr[i] = id[arr[i]];
    }
    vector<int> tree((n + 2) << 2);
    auto update = [&](auto &self, int cur, int l, int r, int k, int x){
        if (l > k || r < k)
            return;
        if (l == r){
            tree[cur] += x;
            return;
        }
        int mid = (l + r) / 2;
        self(self, cur * 2 + 1, l, mid, k, x);
        self(self, cur * 2 + 2, mid + 1, r, k, x);
        tree[cur] = tree[cur * 2 + 1] + tree[cur * 2 + 2];
    };
    auto query = [&](auto &self, int cur, int l, int r, int ql, int qr) -> int {
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[cur];
        int mid = (l + r) / 2;
        return self(self, cur * 2 + 1, l, mid, ql, qr) + self(self, cur * 2 + 2, mid + 1, r, ql, qr);
    };
    ll ans = 0;
    for (int i = 0; i < k; i++){
        ans += query(query, 0, 0, n + 1, arr[i] + 1, n + 1);
        update(update, 0, 0, n + 1, arr[i], 1);
    }
    cout << ans << " \n"[k == n];
    for (int i = k; i < n; i++){
        update(update, 0, 0, n + 1, arr[i - k], -1);
        ans -= query(query, 0, 0, n + 1, 0, arr[i - k] - 1);
        ans += query(query, 0, 0, n + 1, arr[i] + 1, n + 1);
        update(update, 0, 0, n + 1, arr[i], 1);
        cout << ans << " \n"[i == n - 1];
    }
}