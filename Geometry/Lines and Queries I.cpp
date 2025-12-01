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
};

struct node{
    line ln;
    line tag;
};

vector<node> tree;

void push(ll cur, ll l, ll r){
    if (tree[cur].tag.a == 0 && tree[cur].tag.b == -INF)
        return;
    ll mid = (l + r) / 2;
	line temp;
	if (tree[cur].tag.f(mid) > tree[cur].ln.f(mid)){
		temp = tree[cur].ln;
		tree[cur].ln = tree[cur].tag;
	}
	else{
		temp = tree[cur].tag;
	}
	tree[cur].tag = line();
	if (l != r){
		if (tree[cur].ln.a > temp.a){
			tree[cur * 2 + 1].tag = temp;
			push(cur * 2 + 1, l, mid);
		}
		else{
			tree[cur * 2 + 2].tag = temp;
			push(cur * 2 + 2, mid + 1, r);
		}
	}
}

void update(ll cur, line new_ln, ll l, ll r, ll ql, ll qr){
	push(cur, l, r);
    if (ql <= l && r <= qr){
    	tree[cur].tag = new_ln;
		push(cur, l, r);
		return;	
	}
	if (l > qr && r < ql)
		return;

    ll mid = (l + r) / 2;
	update(cur * 2 + 1, new_ln, l, mid, ql, qr);
	update(cur * 2 + 2, new_ln, mid + 1, r, ql, qr);
}

ll query(ll cur, ll l, ll r, ll x){
	push(cur, l, r);
    if (x < l || x > r)
        return -INF;
    if (l == r)
        return tree[cur].ln.f(x);
    ll mid = (l + r) / 2;
    return max(tree[cur].ln.f(x), max(query(cur * 2 + 1, l, mid, x), query(cur * 2 + 2, mid + 1, r, x)));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
	int l = 0, r = 1e5;
    tree.resize((r - l + 1) << 2);
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
