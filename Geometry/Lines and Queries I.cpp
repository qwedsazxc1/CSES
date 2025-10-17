#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

struct line{
    ll a, b;
    line(ll a = 0, ll b = -INF): a(a), b(b) {}
    ll f(ll x){
        return a * x + b;
    }
}

struct node{
    line ln;
    line tag;
};

void push(){
    for (int i = 0; i < segtree.size(); i++){
        if (segtree[i].tag.a != 0){
            segtree[i].ln = segtree[i].tag;
            segtree[i].tag = line();
        }
    }
}

void update(ll cur, line new_ln, ll l, ll r, ll ql, ll qr){
    if (ql <= l && r <= qr){
        ll mid = (l + r) / 2;
        ll flag1 = new_ln.f(mid) > segtree[cur].ln.f(mid);
        ll flag2 = new_ln.a > segtree[cur].ln.a;
        if (flag1 ^ flag2){


        }
    }

    ll mid = (l + r) / 2;
    if (ql <= mid)
        update(cur * 2 + 1, new_ln, l, mid, ql, qr);
    if (qr > mid)
        update(cur * 2 + 2, new_ln, mid + 1, r, ql, qr);
    if (new_ln.f(mid) > segtree[cur].ln.f(mid))
        segtree[cur].ln = new_ln;
}

ll query(ll cur, ll l, ll r, ll x){
    if (x < l || x > r)
        return -INF;
    if (l == r)
        return segtree[cur].ln.f(x);
    ll mid = (l + r) / 2;
    return max(query(cur * 2 + 1, l, mid, x), query(cur * 2 + 2, mid + 1, r, x));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll l = 0, r = 1e5;
    vector<node> segtree((r - l + 1) << 2);
    int n, q;
    cin >> n >> q;
    while (q--){
        ll op;
        cin >> op;
        if (op == 1){
            ll a, b;
            cin >> a >> b;
            line new_ln(a, b);
            update(0, new_ln, l, r, l, r);
        }
        else{
            ll x;
            cin >> x;
            cout << query(0, l, r, x) << "\n";
        }
    }
}