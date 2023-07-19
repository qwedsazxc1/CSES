#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> dep;

void dfs(int cur, int prev, int d = 0){
	parent[cur][0] = prev;
	dep[cur] = d;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		dfs(next, cur, d + 1);
	}
}

void build(int n){
	for (int i = 1; i < 18; i++)
		for (int j = 0; j < n; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	graph.resize(n); dep.assign(n, 0);
	parent.assign(n, vector<int> (18));
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	build(n);
	while (q--){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (dep[a] > dep[b])
			swap(a, b);
		int ans = dep[b] - dep[a];
		for (int i = 0; (1 << i) <= ans; i++)
			if (ans & (1 << i))
				b = parent[b][i];
		if (a == b){
			cout << ans << "\n";
			continue;
		}
		for (int i = 17; i >= 0; i--){
			if (parent[a][i] != parent[b][i]){
				a = parent[a][i];
				b = parent[b][i];
				ans += (1 << i) << 1;
			}
		}
		cout << ans + 2 << "\n";
	}
	return 0;
}
