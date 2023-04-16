#include <iostream>
#include <vector>

using namespace std;

struct node{
	long long f, s;
};

int main(){
	int n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<node>> dp(n, vector<node>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0){
				dp[i][j].s = 0;
				dp[i][j].f = arr[i];
				continue;
			}
			dp[i][j].s = min(dp[i - 1][j - 1].f, dp[i][j - 1].f);
			long long sum = arr[i] + dp[i - 1][j - 1].f + dp[i - 1][j - 1].s;
			sum -= dp[i][j].s;
			dp[i][j].f = sum;
		}
	}
	cout << dp[n - 1][n - 1].f << "\n";
	return 0;
}
