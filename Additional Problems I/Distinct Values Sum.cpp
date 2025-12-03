#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;
	map<ll, ll> m;
	vector<ll> cnt(n + 1);
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll prev = cnt[i];
		if (m.find(arr[i]) == m.end()){
			prev += i + 1;
		}
		else{
			ll idx = m[arr[i]];
			prev += (i - idx);
		}
		m[arr[i]] = i;
		cnt[i + 1] = prev;
		ans += prev;
	}
	cout << ans << "\n";
}
