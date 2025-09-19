#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

int main(){
	ll k, n;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	ll rv = x, r = 1;
	ll ans = 0;
	deque<pair<ll, ll>> arr;
	arr.push_back({x, 0});
	while (r < k){
		rv = (rv * a + b) % c;
		while (arr.size() && arr.back().F >= rv)
			arr.pop_back();
		arr.push_back({rv, r});
		r++;
	}
	ans ^= arr[0].F;

	ll idx = 0;
	while (r < n){
		rv = (rv * a + b) % c;
		while (arr.size() && arr.back().F >= rv)
			arr.pop_back();
		arr.push_back({rv, r});
		if (r - arr[0].S >= k){
			arr.pop_front();
		}
		ans ^= arr[idx].F;
		r++;
	}
	cout << ans << "\n";
}
