#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> sieve(ll n){
	vector<ll> res;
	vector<ll> is_prime(n + 1, 1);
	for (ll i = 2; i <= n; i++){
		if (!is_prime[i])
			continue;
		res.push_back(i);
		for (ll j = i * i; j <= n; j += i)
			is_prime[j] = 0;
	}
	return res;
}

int is_prime(ll x, vector<ll> &prime){
	for (auto p: prime){
		if (x == p)
			return 1;
		if (x % p == 0)
			return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	auto prime = sieve((ll)1e6);
	while (t--){
		ll x;
		cin >> x;
		if (x == 1){
			cout << "2\n";
			continue;
		}
		if (x & 1)
			x += 2;
		else
			x++;
		while (!is_prime(x, prime)){
			x += 2;
		}
		cout << x << "\n";
	}
}
