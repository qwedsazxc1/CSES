#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)
using namespace std;

long long mod_inverse(long long a, long long mod = MOD){
	long long res = 1, p = mod - 2;
	while (p){
		if (p & 1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		p >>= 1;
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
	string str;
	cin >> str;
	vector<long long> frac(n + 1);
	frac[0] = frac[1] = 1;
	for (int i = 2; i < (int)frac.size(); i++){
		frac[i] = frac[i - 1] * i % MOD;
	}
	int l = 0, r = 0;
	bool valid = true;
	for (auto it = str.begin(); it != str.end(); it++){
		if (*it == '(')
			l++;
		else
			r++;
		if (r > l || l > n / 2){valid = false; break;}
	}
	if (!valid){
		cout << "0\n";
		return 0;
	}
	int ll = n / 2 - l, lr = n / 2 - r;
	long long com = frac[n - (int)str.size()] * mod_inverse(frac[ll] * frac[lr] % MOD) % MOD;
	com *= (long long)(lr + 1 - ll);
	com %= MOD;
	com *= mod_inverse((long long)lr + 1);
	com %= MOD;
	cout << com << "\n";
	return 0;
}
