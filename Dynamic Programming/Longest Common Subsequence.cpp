#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(m + 1));
	vector<int> arr1(n), arr2(m);
	for (auto &x: arr1)
		cin >> x;
	for (auto &x: arr2)
		cin >> x;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr1[i - 1] == arr2[j - 1]){
				prev[i][j] = {i - 1, j - 1};
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				if (dp[i - 1][j] > dp[i][j - 1]){
					dp[i][j] = dp[i - 1][j];
					prev[i][j] = {i - 1, j};
				}
				else{
					dp[i][j] = dp[i][j - 1];
					prev[i][j] = {i, j - 1};
				}
			}
		}
	}
	vector<int> ans;
	pair<int, int> cur = {n, m};
	while (cur.first != 0 && cur.second != 0){
		auto next = prev[cur.first][cur.second];
		if (next.first != cur.first && next.second != cur.second)
			ans.push_back(arr1[next.first]);
		cur = next;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " \n"[i + 1 == ans.size()];
	}
}
