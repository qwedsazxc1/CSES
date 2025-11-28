#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<char>> arr(n, vector<char>(n));
	for (auto &a: arr)
		for (auto &x: a)
			cin >> x;
	vector<ll> ans(k);
	vector<vector<ll>> dp(n, vector<ll>(n)), xmax(n, vector<ll>(n)), ymax(n, vector<ll>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			dp[i][j] = 1;
			if (i > 0 && arr[i][j] == arr[i - 1][j])
				xmax[i][j] = xmax[i - 1][j] + 1;
			else
				xmax[i][j] = 1;
			if (j > 0 && arr[i][j] == arr[i][j - 1])
				ymax[i][j] = ymax[i][j - 1] + 1;
			else
				ymax[i][j] = 1;
			if (i > 0 && j > 0 && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1])
				dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			else{
				dp[i][j] += xmax[i][j] - 1;
				dp[i][j] += ymax[i][j] - 1;
			}
			ans[arr[i][j] - 'A'] += dp[i][j];
		}
	}
	for (int i = 0; i < k; i++)
		cout << ans[i] << "\n";
}
