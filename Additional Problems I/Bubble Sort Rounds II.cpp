#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> ans;
	ans.reserve(n);
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(x);
		if (pq.size() > k){
			ans.push_back(pq.top());
			pq.pop();
		}
	}
	while (pq.size()){
		ans.push_back(pq.top());
		pq.pop();
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
}
