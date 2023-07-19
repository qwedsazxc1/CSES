#include <bits/stdc++.h>

using namespace std;

struct edge{
	int u, v;
};

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<edge> ans;
	ans.reserve(1e5);
	set<pair<int, int>> s;
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] >= n){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		if (arr[i] != 0)
			s.insert({arr[i], i});
	}
	if (sum & 1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	stack<int> temp;
	for (int i = 0; i < n; i++){
		if (arr[i] == 0)
			continue;
		
		int ori = arr[i];
		for (auto it = s.rbegin(); it != s.rend() && arr[i] > 0; it++, arr[i]--){
			if (it->second == i){
				arr[i]++;
				continue;
			}
			temp.push(it->second);
		}
		while (!temp.empty()){
			int cur = temp.top();
			temp.pop();
			ans.push_back({i + 1, cur + 1});
			s.erase(s.find({arr[cur], cur}));
			arr[cur]--;
			if (arr[cur] != 0)
				s.insert({arr[cur], cur});
		}
		if (arr[i] > 0){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		s.erase(s.find({ori, i}));
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].u << " " << ans[i].v << "\n";
	return 0;
}
