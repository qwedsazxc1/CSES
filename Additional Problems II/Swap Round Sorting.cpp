#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<vector<pair<int, int>>> ans;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		arr[i]--;
		if (arr[i] != i)
			cnt++;
	}
	if (!cnt){
		cout << "0\n";
		return 0;
	}
	ans.push_back(vector<pair<int, int>>(0));
	vector<int> vis(n);
	for (int i = 0; i < n; i++){
		if (!vis[i] && arr[i] != i){
			vector<int> temp;
			int cur = arr[i];
			temp.push_back(i);
			vis[i] = 1;
			while (cur != i){
				temp.push_back(cur);
				vis[cur] = 1;
				cur = arr[cur];
			}
			int n = temp.size();
			for (int i = 0; i < n / 2; i++){
				ans[0].push_back({temp[i] + 1, temp[n - i - 1] + 1});
				swap(arr[temp[i]], arr[temp[n - i - 1]]);
			}
		}
	}
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++){
		if (i != arr[i]){
			temp.push_back({i + 1, arr[i] + 1});
			swap(arr[i], arr[arr[i]]);
		}
	}
	if (temp.size())
		ans.push_back(temp);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].size() << "\n";
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j].F << " " << ans[i][j].S << "\n";
	}

}
