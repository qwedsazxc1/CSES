#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x; 
	vector<ll> ans = arr;
	stack<int> s;
	for (int i = 0; i < n; i++){
		while (s.size() > 0 && arr[s.top()] >= arr[i])
			s.pop();
		if (s.empty()) 
			ans[i] += i * arr[i];
		else
			ans[i] += (i - s.top() - 1) * arr[i];
		s.push(i);
	}
	while (s.size() > 0) s.pop();
	for (int i = n - 1; i >= 0; i--){
		while (s.size() > 0 && arr[s.top()] >= arr[i])
			s.pop();
		if (s.empty())
			ans[i] += (n - i - 1) * arr[i];
		else
			ans[i] += (s.top() - i - 1) * arr[i];
		s.push(i);
	}
	ll res = ans[0];
	for (int i = 1; i < n; i++)
		res = max(res, ans[i]);
	cout << res << "\n";
	return 0;
}
