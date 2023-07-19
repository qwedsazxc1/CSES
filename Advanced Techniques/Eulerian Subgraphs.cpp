#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
const int N = 1e5;
typedef long long ll;

ll k = 0;
ll cnt = 0;
vector<int> graph[N];
ll visited[N] = {};

void dfs(int cur, int prev){
	visited[cur] = ++cnt;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		if (!visited[next])
			dfs(next, cur);
		else if (visited[next] < visited[cur])
			k++;
	}
}

ll fast_pow(ll base, ll power){
	ll res = 1;
	while (power){
		if (power & 1){
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		power >>= 1;
	}
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i, i);
	cout << fast_pow(2, k) << "\n";
	return 0;	
}
