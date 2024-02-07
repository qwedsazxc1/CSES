#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct operation{
	ll op, y, l, r;
	bool operator<(operation b){
		if (y == b.y)
			return op < b.op;
		return y < b.y;
	}
};

struct node{
	ll sum = 0, cnt = 0;
};

vector<node> tree;

void pull(int id, int l, int r){
	if (l == r)
		tree[id].sum = !!tree[id].cnt;
	else
		tree[id].sum = (tree[id].cnt ? (r - l + 1) : (tree[id * 2 + 1].sum + tree[id * 2 + 2].sum));
}

void update(int id, int l, int r, int ql, int qr, ll x){
	if (r < ql || l > qr)
		return;
	if (l >= ql && r <= qr){
		tree[id].cnt += x;
		pull(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2 + 1, l, mid, ql, qr, x);
	update(id * 2 + 2, mid + 1, r, ql, qr, x);
	pull(id, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	tree.resize(((int)2e6 + 1) << 2);
	int n;
	cin >> n;
	vector<operation> arr(2 * n);
	for (int i = 0; i < n; i++){
		ll lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;
		lx += 1e6;
		ly += 1e6;
		rx += 1e6;
		ry += 1e6;
		rx--;
		arr[i] = {1, ly, lx, rx};
		arr[i + n] = {-1, ry, lx, rx};
	}
	ll ans = 0;
	sort(arr.begin(), arr.end());
	ll prev = 0;
	for (int i = 0; i < 2 * n; i++){
		ans += ((arr[i].y - prev) * tree[0].sum);
		update(0, 0, (int)2e6, arr[i].l, arr[i].r, arr[i].op);
		prev = arr[i].y;
	}
	cout << ans << "\n";
}
