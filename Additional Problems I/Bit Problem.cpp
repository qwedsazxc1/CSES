#include <bits/stdc++.h>

using namespace std;
const int m = 20;
int dp[1 << m][3] = {};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x: arr){
		cin >> x;
		dp[x][0]++;
		dp[x][1]++;
	}
	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << m); mask++){
			if (mask & (1 << i)){
				dp[mask][0] += dp[mask ^ (1 << i)][0];
				dp[mask ^ (1 << i)][1] += dp[mask][1];
			}
		}
	}
	for (auto x: arr){
		cout << dp[x][0] << " " << dp[x][1] << " " << n - dp[((1 << m) - 1) ^ x][0] << "\n";
	}
	return 0;
}
