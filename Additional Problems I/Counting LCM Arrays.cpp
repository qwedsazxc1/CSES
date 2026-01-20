#include <bits/stdc++.h>
#define MOD ((ll)1e9 + 7)

using namespace std;
using ll = long long;

struct matrix{
	vector<vector<ll>> arr;
	matrix(int n, int m) : arr(n, vector<ll>(m)) {}
	matrix operator*(matrix &b) & {
		matrix res(arr.size(), b.arr[0].size());
		for (int i = 0; i < arr.size(); i++){
			for (int j = 0; j < res.arr[0].size(); j++){
				for (int k = 0; k < res.arr.size(); k++){
					res.arr[i][j] += arr[i][k] * b.arr[k][j];
				}
				res.arr[i][j] %= MOD;
			}
		}
		return res;
	}
};

ll fp(ll base, ll power){
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	const ll maxn = 32000; // >> sqrt(1e9)
	vector<ll> prime, is_prime(maxn + 1, 1);
	auto sieve = [&]() -> void {
		is_prime[1] = is_prime[0] = 0;
		for (ll i = 2; i <= maxn; i++){
			if (!is_prime[i])
				continue;
			prime.push_back(i);
			for (ll j = i * i; j <= maxn; j += i){
				is_prime[j] = 0;
			}
		}
	};
	sieve();

	auto factorization = [&](ll k) -> vector<pair<ll, ll>>{
		vector<pair<ll, ll>> res;
		for (auto p: prime){
			if (p * p > k)
				break;
			if (k % p == 0){
				ll cnt = 0;
				while (k % p == 0){
					k /= p;
					cnt++;
				}
				res.push_back({p, cnt});
			}
		}
		if (k != 1)
			res.push_back({k, 1});
		return res;
	};
	
	const ll logn = 30;
	vector<vector<matrix>> dp(logn, vector<matrix>(logn, matrix(2, 2)));
	for (int i = 0; i < logn; i++){
		matrix base(2, 2);
		base.arr[0][0] = base.arr[0][1] = 1;
		base.arr[1][0] = i;
		for (int j = 0; j < logn; j++){
			dp[i][j] = base;
			base = base * base;
		}
	}

	auto fast_pow = [&](ll cnt, ll power) -> matrix {
		matrix res(2, 1);
		res.arr[0][0] = 1;
		for (int i = 0; i < logn; i++){
			if ((1 << i) & power)
				res = dp[cnt][i] * res;
		}
		return res;
	};

	int t;
	cin >> t;
	while (t--){
		ll n, k;
		cin >> n >> k;
		if (k == 1){
			cout << "1\n";
			continue;
		}
		auto factors = factorization(k);
		vector<ll> dpv(logn, -1);
		ll ans = 1;
		for (auto [p, cnt]: factors){
			if (dpv[cnt] == -1){
				auto res = fast_pow(cnt, n);
				ll temp = res.arr[0][0] + res.arr[1][0];
				temp %= MOD;
				dpv[cnt] = temp;
			}
			ans *= dpv[cnt];
			ans %= MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
