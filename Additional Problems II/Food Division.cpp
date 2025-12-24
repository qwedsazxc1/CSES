#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> arr(n), tar(n);
	for (auto &x: arr)
		cin >> x;
	for (auto &x: tar)
		cin >> x;
	ll sum = 0;
	vector<ll> temp(n);
	temp[0] = arr[0] - tar[0];
	for (int i = 1; i < n; i++){
		temp[i] = temp[i - 1] + arr[i] - tar[i];
	}
	sort(temp.begin(), temp.end());
	ll mid = -temp[n / 2];
	ll ans = 0;
	for (int i = 0; i < n; i++){
		ans += abs(mid + temp[i]);
	}
	cout << ans << "\n";
}
