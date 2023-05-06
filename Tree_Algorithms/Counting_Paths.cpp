#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> dep;
vector<int> dp;

void dfs(int cur, int prev, int d){
	dep[cur] = d;
	parent[cur][0] = prev;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		dfs(next, cur, d + 1);
	}
}

void build(int n){
	for (int i = 1; i < 18; i++)
		for (int j = 0; j < n; j++){
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
}

void dfs2(int cur, int prev){
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		dfs2(next, cur);
		dp[cur] += dp[next];
	}
}

int lca(int a, int b){
	if (dep[a] > dep[b])
		swap(a, b);
	int up = dep[b] - dep[a];
	for (int i = 0; (1 << i) <= up; i++){
		if ((1 << i) & up)
			b = parent[b][i];
	}
	if (a == b)
		return a;
	for (int i = 17; i >= 0; i--){
		if (parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main(){
	int n, q;
	cin >> n >> q;
	graph.resize(n);
	dep.resize(n); parent.assign(n, vector<int> (18));
	dp.assign(n, 0);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0, 0);
	build(n);
	while (q--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		int p = lca(a, b);
		dp[a]++;
		dp[b]++;
		dp[p]--;
		if (p != 0)
			dp[parent[p][0]]--;
	}
	dfs2(0, 0);
	for (auto x: dp)
		cout << x << " ";
	cout << "\n";
	return 0;
}
