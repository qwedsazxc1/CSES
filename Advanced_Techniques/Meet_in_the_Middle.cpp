#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll k;
	int n, half;
	cin >> n >> k;
	half = n / 2 + (n & 1);
	ll arr[n], left[(1 << half)];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < (1 << half); i++){
		ll res = 0;
		for (int j = 0; j < half; j++){
			if ((1 << j) & i)
				res += arr[j];
		}
		left[i] = res;
	}
	unordered_map<ll, ll> right;
	int ramount = n - half;
	for (int i = 0; i < (1 << ramount); i++){
		ll res = 0;
		for (int j = 0; j < ramount; j++){
			if ((1 << j) & i)
				res += arr[j + half];
		}
		right[res] += 1;
	}
	ll ans = 0;
	for (int i = 0; i < (1 << half); i++){
		ll cur = left[i];
		auto it = right.find(k - cur);
		if (it == right.end())
			continue;
		ans += (*it).second;
	}
	cout << ans << "\n";
	return 0;
}
