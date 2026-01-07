#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int l = 0, r = 0;
	ll ans = 0;
	vector<int> a(n), b(n);
	for (auto &x: a)
		cin >> x;
	for (auto &x: b)
		cin >> x;
	for (int i = 0; i < n; i++){
		int x = a[i], y = b[i];
		l += x;
		r += y;
		ans += abs(2 * (i + 1) - (l + r));
	}
	ans += abs(l - n);
	cout << ans << "\n";
}
