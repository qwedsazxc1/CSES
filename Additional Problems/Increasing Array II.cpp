#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll ans = 0;
	priority_queue<ll> pq;
	for (int i = 0; i < n; i++){
		ll in;
		cin >> in;
		pq.push(in);
		ans -= in - pq.top();
		pq.pop();
		pq.push(in);
	}
	cout << ans << "\n";
	return 0;
}
