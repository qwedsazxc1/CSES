#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll B = 32767, M = 1e9 + 7;
vector<ll> _pow, revpow;

void build_pow(int n){
	_pow.resize(n + 2);
	_pow[0] = 1;
	for (int i = 1; i <= n; i++)
		_pow[i] = _pow[i - 1] * B % M;
	revpow = _pow;
	reverse(revpow.begin(), revpow.end());
}


struct node{
	ll hv, rhv;
};

vector<node> tree;


void update(int id, int l, int r, int k, char c){
	if (l > k || r < k)
		return;
	if (l == r){
		tree[id].hv = (ll)c * _pow[l] % M;
		tree[id].rhv = (ll)c * revpow[l] % M;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 + 1, l, mid, k, c);
	update(id * 2 + 2, mid + 1, r, k, c);
	tree[id].hv = (tree[id * 2 + 1].hv + tree[id * 2 + 2].hv) % M;
	tree[id].rhv = (tree[id * 2 + 1].rhv + tree[id * 2 + 2].rhv) % M;
}

node query(int id, int l, int r, int ql, int qr){
	if (r < ql || l > qr)
		return {0, 0};
	if (l >= ql && r <= qr)
		return tree[id];
	int mid = (l + r) / 2;
	auto lres = query(id * 2 + 1, l, mid, ql, qr);
	auto rres = query(id * 2 + 2, mid + 1, r, ql, qr);
	node res;
	res.hv = (lres.hv + rres.hv) % M;
	res.rhv = (lres.rhv + rres.rhv) % M;
	return res;
}

bool check(int s, int e, int n){
	auto res = query(0, 1, n, s, e);
	res.hv *= _pow[n - s + 1];
	res.hv %= M;
	res.rhv *= _pow[e];
	res.rhv %= M;
	return res.hv == res.rhv;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	tree.resize(n << 2);
	build_pow(n);
	for (int i = 0; i < n; i++)
		update(0, 1, n, i + 1, str[i]);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int k;
			char c;
			cin >> k >> c;
			update(0, 1, n, k, c);
		}
		else{
			int l, r;
			cin >> l >> r;
			if (check(l, r, n))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
