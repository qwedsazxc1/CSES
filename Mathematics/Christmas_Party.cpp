#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

ll mod_inverse(ll a, ll mod = MOD){
	ll p = mod - 2, base = a, res = 1;
	while (p){
		if (p & 1){
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;
		p >>= 1;
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	vector<ll> frac(n + 1), inv(n + 1);
	frac[0] = 1;
	inv[0] = 1;
	for (ll i = 1; i <= n; i++){
		frac[i] = frac[i - 1] * i % MOD;
		inv[i] = mod_inverse(frac[i]);
	}
	ll bit = 1, ans = 0;
	for (ll i = 0; i <= n; i++, bit = -bit){
		ans += frac[n] * inv[i] % MOD * bit;
		ans %= MOD;
		if (ans < 0)
			ans += MOD;
	}
	cout << ans << "\n";
	return 0;
}
