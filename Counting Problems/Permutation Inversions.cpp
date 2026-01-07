#include <bits/stdc++.h>
#define MOD ((ll)1e9 + 7)

using namespace std;
using ll = long long;



int main(){
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> cnt(n, vector<ll>(k + 1));
	auto pre = [&](int idx) -> void {
		for (int i = 1; i <= k; i++){
			cnt[idx][i] += cnt[idx][i - 1];
			cnt[idx][i] %= MOD;
		}
	};
	auto query = [&](int idx, int l, int r) -> ll {
		if (r > k)
			r = k;
		if (l < 1)
			return cnt[idx][r];
		ll res = cnt[idx][r] - cnt[idx][l - 1];
		res %= MOD;
		res += MOD;
		res %= MOD;
		return res;
	};
	cnt[0][0] = 1;
	pre(0);
	for (int i = 1; i < n; i++){
		for (int j = 0; j <= k; j++){
			cnt[i][j] = query(i - 1, j - i, j);
		}
		pre(i);
	}
	cout << query(n - 1, k, k) << "\n";
}
