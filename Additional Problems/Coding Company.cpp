#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

int offset = 1e4;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int sum = 0;
	vector<vector<ll>> dp(1, vector<ll>(1, 1));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++){
		vector<vector<ll>> next(i + 2, vector<ll>(sum + arr[i] + x + 1));
		for (int j = 0; j <= i; j++){
			for (int k = 0; k < dp[0].size(); k++){
				if (dp[j][k]){
					next[j][k + arr[i]] += dp[j][k];
					if (j && k + 2 * arr[i] < next[0].size()){
						next[j - 1][k + 2 * arr[i]] += j * dp[j][k];
						next[j - 1][k + 2 * arr[i]] %= MOD;
					}
					next[j + 1][k] += dp[j][k];
					next[j + 1][k] %= MOD;
					next[j][k + arr[i]] += j * dp[j][k];
					next[j][k + arr[i]] %= MOD;
				}
			}
		}
		dp = next;
		sum += arr[i];
	}
	ll ans = 0;
	for (int i = sum; i < dp[0].size(); i++){
		ans += dp[0][i];
		ans %= MOD;
	}
	cout << ans << "\n";
}
