#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

ll dp[(1 << 10)][2] = {};

int main(){
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			for (int mask = 0; mask < (1 << n); mask++){
				dp[mask][1] = dp[mask ^ (1 << j)][0];
				if (!((1 << j) & mask)){
					if (j > 0 && !((1 << (j - 1)) & mask)){
						dp[mask][1] += dp[mask ^ (1 << (j - 1))][0];
						dp[mask][1] %= MOD;
					}
				}
				
			}
			for (int mask = 0; mask < (1 << n); mask++)
				dp[mask][0] = dp[mask][1];
		}
	}
	cout << dp[0][0] << "\n";
	return 0;
}
