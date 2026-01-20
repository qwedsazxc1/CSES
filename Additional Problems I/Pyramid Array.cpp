#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> arr(n);
	vector<pair<ll, ll>> temp(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		temp[i].F = arr[i];
		temp[i].S = i;
	}
	sort(temp.begin(), temp.end());
	for (int i = 0; i < n; i++)
		arr[temp[i].S] = i;
	ll ans = 0;
	vector<ll> tree(n << 2);
	auto update = [&](auto &self, int cur, int l, int r, int k) -> void {
		if (l > k || r < k)
			return;
		if (l == r)
			return tree[cur] = 1, void();
		int mid = (l + r) / 2;
		self(self, cur * 2 + 1, l, mid, k);
		self(self, cur * 2 + 2, mid + 1, r, k);
		tree[cur] = tree[cur * 2 + 1] + tree[cur * 2 + 2];
	};
	auto query = [&](auto &self, int cur, int l, int r, int ql, int qr) -> ll {
		if (l >= ql && r <= qr)
			return tree[cur];
		if (r < ql || l > qr)
			return 0;
		int mid = (l + r) / 2;
		return self(self, cur * 2 + 1, l, mid, ql, qr) + self(self, cur * 2 + 2, mid + 1, r, ql, qr);
	};
	for (int i = 0; i < n; i++){
		int idx = temp[i].S;
		int ldis = idx, rdis = n - idx - 1;
		ldis -= query(query, 0, 0, n - 1, 0, idx);
		rdis -= query(query, 0, 0, n - 1, idx, n - 1);
		ans += min(ldis, rdis);
		update(update, 0, 0, n - 1, idx);
	}
	cout << ans << "\n";
}
