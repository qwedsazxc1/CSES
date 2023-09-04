#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)
using namespace std;

typedef long long ll;

int maxn;
vector<ll> bit;

void update(int k, ll x){
	for (k++; k <= maxn; k += k & -k){
		bit[k] += x;
		bit[k] %= MOD;
	}
}

ll query(int r){
	ll res = 0;
	for (r++; r > 0; r -= r & -r){
		res += bit[r];
		res %= MOD;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	bit.assign(n + 2, 0);
	maxn = n + 1;
	vector<int> arr(n);
	map<int, int> m;
	for (auto &x : arr){
		cin >> x;
		m[x];
	}
	int t = 0;
	for (auto &p: m) p.second = ++t;
	for (auto &x: arr) x = m[x];
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll temp = query(arr[i] - 1) + 1;
		ans += temp;
		ans %= MOD;
		update(arr[i], temp);
	}
	cout << ans << "\n";
	return 0;
}
