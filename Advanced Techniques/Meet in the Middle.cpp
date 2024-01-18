#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l[(1 << 20)];

int main(){
	ll k;
	int n, half;
	cin >> n >> k;
	half = n / 2 + (n & 1);
	ll arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < (1 << half); i++){
		ll res = 0;
		for (int j = 0; j < half; j++){
			if ((1 << j) & i)
				res += arr[j];
		}
		l[i] = res;
	}
	unordered_map<ll, ll> right;
	right.reserve(4096);
	right.max_load_factor(0.25);
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
		ll cur = l[i];
		auto it = right.find(k - cur);
		if (it == right.end())
			continue;
		ans += (*it).second;
	}
	cout << ans << "\n";
	return 0;
}
