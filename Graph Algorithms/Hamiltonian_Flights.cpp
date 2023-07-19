#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)
using namespace std;

int dp[1 << 20][20];
vector<vector<int>> adj;
int n;

long long rec(int mask, int index){
	if (dp[mask][index] != -1)
		return dp[mask][index];
	int res = 0, mask1 = mask ^ (1 << index);
	for (auto e: adj[index]){
		if ((1 << e) & mask){
			res = (res + rec(mask1, e)) % MOD;
		} 
	}
	return dp[mask][index] = res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u == v)
			continue;
		adj[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++){
		dp[1 << i][i] = 0;
	}
	dp[1][0] = 1;
	cout << rec((1 << n) - 1, n - 1) << "\n";
	return 0;
}
