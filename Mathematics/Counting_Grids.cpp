#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

ll pow(ll base, ll power){
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

ll module_inverse(ll a){
	return pow(a, MOD - 2);
}

int main(){
	ll n;
	cin >> n;

	ll ans = 0;

	// 0 degree rotate
	ans += pow(2LL, (n * n));
	ans %= MOD;

	// 90 and 270 degree rotate
	if (n & 1){
		ans += pow(2LL, (n / 2) * (n / 2 + 1) + 1) * 2;
		ans %= MOD;
	}
	else{
		ans += pow(2LL, n * n / 4) * 2;
		ans %= MOD;
	}

	// 180 degree rotate
	if (n & 1){
		ans += pow(2LL, (n / 2 + 1) * n - (n / 2));
		ans %= MOD;
	}
	else{
		ans += pow(2LL, n * n / 2);
		ans %= MOD;
	}
	ans *= module_inverse(4);
	ans %= MOD;

	cout << ans << "\n";
	return 0;
}
