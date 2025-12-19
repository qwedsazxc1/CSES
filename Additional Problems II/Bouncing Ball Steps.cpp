#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		ll n, m, t;
		cin >> n >> m >> t;
		ll c = 0;
		ll temp = t / (n - 1);
		ll rem = t % (n - 1);
		c += temp;
		ll x = 1, y = 1;
		if (temp & 1)
			x = n - rem;
		else
			x += rem;
		temp = t / (m - 1);
		rem = t % (m - 1);
		c += temp;
		if (temp & 1)
			y = m - rem;
		else
			y += rem;
		ll g = gcd(n - 1, m - 1);
		ll l = (n - 1) / g * (m - 1);
		c -= t / l;
		cout << x << " " << y << " " << c << "\n";
	}
}
