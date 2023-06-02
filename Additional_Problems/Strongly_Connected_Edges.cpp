#include <bits/stdc++.h>

using namespace std;

struct edge{int u, v;};

int t = 0;
vector<int> low, visited;
vector<edge> ans;
vector<vector<int>> graph;

void dfs(int cur, int prev){
	low[cur] = visited[cur] = ++t;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		ans.push_back((edge){cur + 1, next + 1});
		if (visited[next] == 0){
			dfs(next, cur);
			low[cur] = min(low[cur], low[next]);
		}
		else{
			if (visited[cur] < visited[next])
				ans.pop_back();
			low[cur] = min(low[cur], visited[next]);
		}
	}
	if (low[cur] == visited[cur] && cur != 0){
		cout << "IMPOSSIBLE\n";
		exit(0);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	low.resize(n); visited.assign(n, 0); ans.reserve(m);
	dfs(0, 0);

	for (int i = 0; i < n; i++)
		if (visited[i] == 0){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	for (int i = 0; i < m; i++)
		cout << ans[i].u << " " << ans[i].v << "\n";
	return 0;
}
