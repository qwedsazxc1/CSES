#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int k, n;
	cin >> k >> n;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < n; i++){
		ll input;
		cin >> input;
		pq.push(input);
	}
	long long ans = 0;
	while (pq.size() > 1){
		ll top1 = pq.top(); pq.pop();
		ll top2 = pq.top(); pq.pop();
		ans += top1 + top2;
		pq.push(top1 + top2);
	}
	cout << ans << "\n";
	return 0;
}
