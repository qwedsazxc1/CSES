#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<char>> arr(n, vector<char>(n));
	for (auto &a:arr)
		for (auto &x: a)
			cin >> x;
	vector<vector<ll>> dp(n, vector<ll>(n));
	vector<ll> ans(k);
	dp[0][0] = 1;
	ans[arr[0][0] - 'A']++;
	for (int i = 1; i < n; i++){
		dp[0][i] = dp[i][0] = 1;
		ans[arr[0][i] - 'A']++;
		ans[arr[i][0] - 'A']++;
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < n; j++){
			if (arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1]){
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
			}
			else{
				dp[i][j] = 1;
			}
			ans[arr[i][j] - 'A'] += dp[i][j];
		}
	}
	for (int i = 0; i < k; i++){
		cout << ans[i] << "\n";
	}
}
