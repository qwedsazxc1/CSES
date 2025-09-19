#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll n, k;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	ll lv = x, sum = x, ans = 0, rv = x;
	ll r = 0, l = 0;
	while (r + 1 < k){
		r++;
		rv = (a * rv + b) % c;
		sum += rv;
	}
	ans ^= sum;
	while (r + 1 < n){
		sum -= lv;
		rv = (a * rv + b) % c;
		sum += rv;
		ans ^= sum;
		lv = (a * lv + b) % c;
		r++;
	}
	cout << ans << "\n";
}
