#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

struct line{
	ll a, b;
	line(ll a = 0, ll b = -INF) : a(a), b(b) {}
	ll f(ll x){ return a * x + b; }
};

struct node{
	line ln, tag;
};

vector<node> tree;

void push(int cur, int l, int r){
	if (tree[cur].tag.a == 0 && tree[cur].tag.b == -INF)
		return;
	line temp = tree[cur].tag;
	tree[cur].tag = line();
	ll mid = (l + r) / 2;
	if (temp.f(mid) > tree[cur].ln.f(mid)){
		swap(temp, tree[cur].ln);
	}
	if (l == r)
		return;
	if (tree[cur].ln.a > temp.a){
		push(cur * 2 + 1, l, mid);
		tree[cur * 2 + 1].tag = temp;
		push(cur * 2 + 1, l, mid);
	}
	else{
		push(cur * 2 + 2, mid + 1, r);
		tree[cur * 2 + 2].tag = temp;
		push(cur * 2 + 2, mid + 1, r);
	}
}

void update(int cur, int l, int r, int ql, int qr, line x){
	push(cur, l, r);
	if (l >= ql && r <= qr){
		tree[cur].tag = x;
		push(cur, l, r);
		return;
	}
	if (l > qr || r < ql)
		return;
	int mid = (l + r) / 2;
	update(cur * 2 + 1, l, mid, ql, qr, x);
	update(cur * 2 + 2, mid + 1, r, ql, qr, x);
}

ll query(int cur, int l, int r, int x){
	push(cur, l, r);
	if (l > x || r < x)
		return -INF;
	if (l == r)
		return tree[cur].ln.f(x);
	int mid = (l + r) / 2;
	return max(max(tree[cur].ln.f(x), query(cur * 2 + 1, l, mid, x)), query(cur * 2 + 2, mid + 1, r, x));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	int l = 0, r = 1e5;
	tree.resize((r - l + 1) << 2);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			ll a, b, ql, qr;
			cin >> a >> b >> ql >> qr;
			line temp(a, b);
			update(0, l, r, ql, qr, temp);
		}
		else{
			ll x;
			cin >> x;
			ll res = query(0, l, r, x);
			if (res == -INF){
				cout << "NO\n";
			}
			else
				cout << res << "\n";
		}
	}
}
