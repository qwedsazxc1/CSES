#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;
const int maxn = 3e3 + 5;

ll cost[maxn][maxn];
ll dp[maxn][maxn], pos[maxn][maxn];

void build(vector<ll> &arr){
	int n = arr.size();
	vector<ll> pre(n + 1);
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + arr[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			cost[i][j] = (pre[j] - pre[i - 1]) * (pre[j] - pre[i - 1]);
		}
}

void calc(int j, int a, int b, int x, int y){
	if (a > b)
		return;
	int mid = (a + b) / 2, p = mid - 1;
	ll min_cost = INF;
	// calculate dp[mid][j] and pos[mid][j]
	for (int i = max(j, x); i <= min(y, mid); i++){
		if (min_cost > dp[i - 1][j - 1] + cost[i][mid]){
			min_cost = dp[i - 1][j - 1] + cost[i][mid];
			p = i;
		}
	}
	dp[mid][j] = min_cost, pos[mid][j] = p;
	calc(j, a, mid - 1, x, p);
	calc(j, mid + 1, b, p, y);
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;
	build(arr);
	for (int i = 1; i <= n; i++)
		dp[i][1] = cost[1][i];
	for (int j = 2; j <= n; j++)
		calc(j, 1, n, 1, n);
	cout << dp[n][k] << "\n";
	return 0;
}
