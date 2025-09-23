#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
    ll sum = 0;
    ll l = 0;
    ll r = 0;
    ll res = 0;
};

vector<node> tree;

node construct(int val){
    node res;
    res.sum = val;
    res.l = max(0, val);
    res.r = max(0, val);
    res.res = max(0, val);
    return res;
}

node pull(node a, node b){
    node res;
    res.sum = a.sum + b.sum;
    res.l = max(a.l, a.sum + b.l);
    res.r = max(b.r, b.sum + a.r);
    res.res = max(max(a.res, b.res), a.r + b.l);
    return res;
}

void update(int cur, int l, int r, int k, ll x){
    if (l > k || r < k) return;
    if (l == r){
        tree[cur] = construct(x);
        return;
    }
    int mid = (l + r) / 2;
    update(cur * 2 + 1, l, mid, k, x);
    update(cur * 2 + 2, mid + 1, r, k, x);
    tree[cur] = pull(tree[cur * 2 + 1], tree[cur * 2 + 2]);
}

node query(int cur, int l, int r, int ql, int qr){
    if (l > qr || r < ql) return construct(0);
    if (l >= ql && r <= qr) return tree[cur];
    int mid = (l + r) / 2;
    return pull(query(cur * 2 + 1, l, mid, ql, qr), query(cur * 2 + 2, mid + 1, r, ql, qr));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    tree.resize(n << 2);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        update(0, 0, n - 1, i, x);
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l - 1, r - 1).res << "\n";
    }
    return 0;
}
