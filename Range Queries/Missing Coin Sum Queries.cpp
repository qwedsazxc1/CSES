#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node{
	ll sum;
	int l, r;
};

vector<node> tree(1);
vector<ll> val;

void update(int &cur, int prev, int l, int r, int k, ll v){
	cur = tree.size();
	tree.push_back(tree[prev]);
	tree[cur].sum += v;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	if (k <= mid){
		update(tree[cur].l, tree[prev].l, l, mid, k, v);
	}
	else{
		update(tree[cur].r, tree[prev].r, mid + 1, r, k, v);
	}
}

ll query(int cur, int l, int r, ll v){
	if (l == r){
		if (val[l] <= v)
			return tree[cur].sum;
		else
			return 0;
	}
	int mid = (l + r) / 2;
	if (val[mid] <= v){
		return tree[tree[cur].l].sum + query(tree[cur].r, mid + 1, r, v);
	}
	else{
		return query(tree[cur].l, l, mid, v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	vector<int> root(n + 1);
	for (auto &x: arr)
		cin >> x;
	val = arr;
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	int m = val.size();
	tree.reserve(n * 30);
	for (int i = 0; i < n; i++){
		int idx = lower_bound(val.begin(), val.end(), arr[i]) - val.begin();
		update(root[i + 1], root[i], 0, m - 1, idx, arr[i]);
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		l--;
		ll ans = 0, prev = -1;
		while (ans != prev){
			prev = ans;
			ans = query(root[r], 0, m - 1, ans + 1) - query(root[l], 0, m - 1, ans + 1);
		}
		cout << ans + 1 << "\n";
	}
}
