#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define F first
#define S second

using namespace std;
using ll = long long;

vector<ll> tree;

const ll maxn = 1e6;

void update(int cur, int l, int r, int k, ll x){
	if (l > k || r < k)
		return;
	if (l == r)
		return tree[cur] = max(x, tree[cur]), void();
	int mid = (l + r) / 2;
	update(cur * 2 + 1, l, mid, k, x);
	update(cur * 2 + 2, mid + 1, r, k, x);
	tree[cur] = max(tree[cur * 2 + 1], tree[cur * 2 + 2]);
}

ll query(int cur, int l, int r, int ql, int qr){
	if (r < ql || l > qr)
		return -1;
	if (l >= ql && r <= qr)
		return tree[cur];
	int mid = (l + r) / 2;
	return max(query(cur * 2 + 1, l, mid, ql, qr), query(cur * 2 + 2, mid + 1, r, ql, qr));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<pair<pair<ll, ll>, ll>> arr(n + q);
	for (int i = 0; i < arr.size(); i++){
		cin >> arr[i].F.F >> arr[i].F.S;
		if (i >= n)
			arr[i].S = i - n + 1;
	}
	ll ans = 0;
	vector<ll> que(q, INF);
	for (int i = 0; i < 4; i++){
		tree.assign((maxn + 1) << 2, -1);
		sort(arr.begin(), arr.end());
		ll temp = INF;
		for (int j = 0; j < arr.size(); j++){
			auto [p, op] = arr[j];
			auto [x, y] = p;
			if (op){
				ll res = query(0, 0, maxn, 0, y);
				if (res != -1)
					que[op - 1] = min(que[op - 1], x + y - res);
			}
			else{
				update(0, 0, maxn, y, x + y);
			}
			
			arr[j].F.F = maxn - arr[j].F.F;
			if (i & 1)
				arr[j].F.S = maxn - arr[j].F.S;
		}
	}
	for (auto &x: que)
		ans = max(ans, x);
	cout << ans << "\n";
}
