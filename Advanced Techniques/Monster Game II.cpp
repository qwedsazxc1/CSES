#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

struct line{
	ll a, b;
	line(ll a = 0, ll b = INF) : a(a), b(b) {}
	ll f(ll x){ return a * x + b; }
};

struct node{
	line ln, tag;
};

vector<node> tree;

void push(int cur, int l, int r){
	if (tree[cur].tag.a == 0 && tree[cur].tag.b == INF)
		return;
	line temp = tree[cur].tag;
	tree[cur].tag = line();
	int mid = (l + r) / 2;
	if (temp.f(mid) < tree[cur].ln.f(mid)){
		swap(temp, tree[cur].ln);
	}
	if (l == r)
		return;
	if (temp.a > tree[cur].ln.a){
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
	if (r < x || l > x)
		return INF;
	if (l == r)
		return tree[cur].ln.f(x);
	int mid = (l + r) / 2;
	return min(min(query(cur * 2 + 1, l, mid, x), query(cur * 2 + 2, mid + 1, r, x)), tree[cur].ln.f(x));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll f;
	cin >> n >> f;
	vector<ll> dp(n);
	ll r = 1e6;
	tree.resize((r + 1) << 2);
	line temp(f, 0);
	update(0, 0, r, 0, r, temp);
	vector<ll> m(n), fa(n);
	for (auto &x: m)
		cin >> x;
	for (auto &x: fa)
		cin >> x;
	for (int i = 0; i < n; i++){
		ll res = query(0, 0, r, m[i]);
		dp[i] = res;
		line temp(fa[i], dp[i]);
		update(0, 0, r, 0, r, temp);
	}
	cout << dp[n - 1] << "\n";
}
