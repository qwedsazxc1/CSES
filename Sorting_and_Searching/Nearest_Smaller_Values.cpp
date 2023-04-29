#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	stack<pair<int, int>> s;
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		while (!s.empty() && s.top().first >= arr[i])
			s.pop();
		if (s.empty()){
			ans[i] = 0;
		}	
		else{
			ans[i] = s.top().second + 1;
		}
		s.push({arr[i], i});
	}
	for (int i = 0 ; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
