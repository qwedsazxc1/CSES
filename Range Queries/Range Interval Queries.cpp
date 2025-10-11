#include <bits/stdc++.h>

using namespace std;

struct query{
    int op, x, l, r, idx;
    bool operator< (const query &o) const{
        if (x == o.x)
            return op < o.op;
        return x < o.x;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<query> queries;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        queries.push_back({0, x, i, i, -1});
    }
    for (int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.push_back({1, c - 1, a - 1, b - 1, i});
        queries.push_back({2, d, a - 1, b - 1, i});
    }
    sort(queries.begin(), queries.end());
    vector<int> tree(n << 2);
    auto update = [&](auto &self, int cur, int l, int r, int k, int x) -> void {
        if (k < l || k > r)
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
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return tree[cur];
        int mid = (l + r) / 2;
        return self(self, cur * 2 + 1, l, mid, ql, qr) + self(self, cur * 2 + 2, mid + 1, r, ql, qr);
    };

    vector<int> ans(q);
    for (auto &cur: queries){
        if (cur.op == 0){
            update(update, 0, 0, n - 1, cur.l, 1);
        } else if (cur.op == 1){
            ans[cur.idx] -= query(query, 0, 0, n - 1, cur.l, cur.r);
        } else {
            ans[cur.idx] += query(query, 0, 0, n - 1, cur.l, cur.r);
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}
