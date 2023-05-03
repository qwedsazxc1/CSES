#include <bits/stdc++.h>

using namespace std;
#define MOD ((long long)1e9 + 7)

long long mod_inverse(long long a, long long mod = MOD){
	long long res = 1, base = a, power = mod - 2;
	while (power){
		if (power & 1){
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;
		power >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	if (n & 1){
		cout << "0\n";
		return 0;
	}
	long long frac[(long long)1e6 + 5];
	frac[1] = frac[0] = 1;
	for (int i = 2; i <= n; i++)
		frac[i] = frac[i - 1] * i % MOD;
	cout << frac[n] * mod_inverse(frac[n / 2] * frac[n / 2 + 1] % MOD) % MOD << "\n";
	return 0;
}
