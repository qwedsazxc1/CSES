#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int main(){
	int a, b, n;
	cin >> a >> b >> n;
	vector<pii> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].F >> arr[i].S;
	auto cmp = [&](pii &a, pii &b) -> bool {
		return (a.F - a.S) > (b.F - b.S);
	};
	sort(arr.begin(), arr.end(), cmp);
	ll ans = 0;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<ll> temp(n + 1);
	ll sum = 0;
	for (int i = n - 1; i >= a; i--){
		sum += arr[i].S;
		pq.push(arr[i].S);
		if (pq.size() > b){
			sum -= pq.top();
			pq.pop();
		}
		temp[i] = sum;
	}
	while(pq.size())
		pq.pop();
	sum = 0;
	for (int i = 0; i < n - b; i++){
		sum += arr[i].F;
		pq.push(arr[i].F);
		if (pq.size() > a){
			sum -= pq.top();
			pq.pop();
		}
		temp[i + 1] += sum;
	}
	for (int i = a; i < n - b + 1; i++)
		ans = max(ans, temp[i]);
	cout << ans << "\n";
}
