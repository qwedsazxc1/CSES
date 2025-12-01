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
	if (temp.f(mid) > tree[cur].ln.f(mid))
		swap(temp, tree[cur].ln);
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
	if (r < ql || l > qr)
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
	return max(max(query(cur * 2 + 1, l, mid, x), query(cur * 2 + 2, mid + 1, r, x)), tree[cur].ln.f(x));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, r;
	cin >> n >> r;
	tree.resize((r + 1) << 2);
	for (int i = 0; i < n; i++){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll a = (y2 - y1) / (x2 - x1);
		ll b = y1 - a * x1;
		line temp(a, b);
		update(0, 0, r, x1, x2, temp);
	}
	for (int i = 0; i <= r; i++){
		ll res = query(0, 0, r, i);
		if (res == -INF)
			res = -1;
		cout << res << " \n"[i == r];
	}
}
