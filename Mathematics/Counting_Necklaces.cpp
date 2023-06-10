#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll pow(ll base, ll p){
	ll res = 1;
	while (p){
		if (p & 1){
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		p >>= 1;
	}
	return res;
}

ll module_inverse(ll a){
	return pow(a, MOD - 2);
}

int main(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans += pow(k, gcd(n, i));
		ans %= MOD;
	}
	ans *= module_inverse(n);
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
