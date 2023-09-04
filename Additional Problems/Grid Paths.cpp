#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

ll frac[(ll)2e6 + 1];

ll fast_pow(ll base, ll power){
	ll res = 1;
	while (power){
		if (power & 1){
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		power >>= 1;
	}
	return res;
}

ll mod_inverse(ll a){
	return fast_pow(a, MOD - 2);
}

ll C(ll n, ll k){
	return frac[n] * mod_inverse(frac[n - k] * frac[k] % MOD) % MOD;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.first + a.second < b.first + b.second;
}

ll cnt_path(pair<ll, ll> a, pair<ll, ll> b){
	if (b.first < a.first || b.second < a.second)
		return 0;
	return C(b.first + b.second - a.first - a.second, b.second - a.second);
}

int main(){
	ll l, n;
	cin >> l >> n;
	l--;
	frac[0] = frac[1] = 1;
	for (ll i = 2; i <= 2e6; i++)
		frac[i] = frac[i - 1] * i % MOD;
	vector<pair<ll, ll>> arr(n);
	ll dp[n] = {};
	for (auto &p: arr){
		cin >> p.first >> p.second;
		p.first--;
		p.second--;
	}
	sort(arr.begin(), arr.end(), cmp);
	ll ans = C(2 * l, l);
	for (int i = 0; i < n; i++){
		dp[i] = cnt_path({0, 0}, arr[i]);
		for (int j = 0; j < i; j++){
			dp[i] -= dp[j] * cnt_path(arr[j], arr[i]) % MOD;
			if (dp[i] < 0)
				dp[i] += MOD;
		}
		ans -= dp[i] * cnt_path(arr[i], {l, l}) % MOD;
		if (ans < 0)
			ans += MOD;
	}
	cout << ans << "\n";
	return 0;
}
