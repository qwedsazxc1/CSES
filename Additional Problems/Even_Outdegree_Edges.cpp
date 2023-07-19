#include <bits/stdc++.h>

using namespace std;

struct edge{
	int u, v;
};
vector<vector<int>> graph;
vector<int> visited, out;
vector<edge> ans;
int t = 0;

void dfs(int cur, int prev){
	visited[cur] = ++t;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		if (!visited[next]){
			dfs(next, cur);
			if (out[next] == 1){
				out[next] = 0;
				ans.push_back({next, cur});
			}
			else{
				out[cur] ^= 1;
				ans.push_back({cur, next});
			}
		}
		else if (visited[cur] > visited[next]){
			ans.push_back({cur, next});
			out[cur] ^= 1;
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	if (m & 1){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	graph.resize(n);
	visited.assign(n, 0);
	out.assign(n, 0);
	ans.reserve(n);
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
	bool flag = true;
	for (int i = 0; i < n; i++){
		if (out[i] == 1){
			flag = false;
			break;
		}
	}
	if (!flag){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	for (int i = 0; i < m; i++){
		cout << ans[i].u + 1 << " " << ans[i].v + 1 << "\n";
	}
	return 0;
}
