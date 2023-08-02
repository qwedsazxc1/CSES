#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;
const int maxn = 5e3 + 1;

ll dp[maxn][maxn], pos[maxn][maxn];

int main(){
	int n;
	cin >> n;
	vector<ll> arr(n), pre(n + 1);
	for (auto &x: arr)
		cin >> x;
	pre[0] = 0;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++){
		pos[i][i] = i;
		dp[i][i] = 0;
		pre[i] = pre[i - 1] + arr[i - 1];
	}
	for (int k = 2; k <= n; k++){
		for (int i = 1, j = 1 + k - 1; j <= n; i++, j++){
			for (int mid = pos[i][j - 1]; mid <= pos[i + 1][j]; mid++){
				if (dp[i][j] > dp[i][mid] + dp[mid + 1][j] + pre[j] - pre[i - 1]){
					dp[i][j] = dp[i][mid] + dp[mid + 1][j] + pre[j] - pre[i - 1];
					pos[i][j] = mid;
				}
			}
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
