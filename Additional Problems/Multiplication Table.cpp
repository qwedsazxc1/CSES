#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll l = 1, r = n * n, ans;
	while (l <= r){
		ll mid = (r + l) / 2;
		ll count = 0;
		for (ll i = 1; i <= n; i++)
			count += min(n, mid / i);
		if (count < (n * n + 1) / 2){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	cout << ans << "\n";
	return 0;
}
