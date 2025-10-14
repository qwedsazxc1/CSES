#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

ll frac[505], inv[505];

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
	return frac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main(){
	string str;
	cin >> str;
	int n = str.size();
	ll dp[n + 1][n + 1];
	inv[0] = inv[1] = frac[0] = frac[1] = 1;
	for (ll i = 2; i < 505; i++){
		frac[i] = frac[i - 1] * i % MOD;
		inv[i] = mod_inverse(frac[i]);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i + 1][i] = 1;
	
	for (int length = 2; length <= n; length++){
		for (int i = 0; i + length <= n; i++){
			for (int j = i + 1; j < i + length; j++){
				if (str[i] == str[j]){
					dp[i][i + length - 1] += (dp[i + 1][j - 1] * dp[j + 1][i + length - 1]) % MOD \
											 * C((length / 2), (j - i + 1) / 2) % MOD;
					dp[i][i + length - 1] %= MOD;
				}
			}
		}
	}
	cout << dp[0][n - 1] << "\n";
	return 0;
}
