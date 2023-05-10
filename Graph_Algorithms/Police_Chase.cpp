#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;
vector<pii> ans;

bool bfs(int node){
	queue<int> q;
	visited.assign(n, false);
	visited[node] = true;
	q.push(node);
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < n; i++){
			if (!graph[f][i] || visited[i])
				continue;
			visited[i] = true;
			q.push(i);
			parent[i] = f;
		}
	}
	return visited[n - 1];
}

int main(){
	int m;
	cin >> n >> m;
	graph.assign(n, vector<int> (n, 0));
	parent.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	while (bfs(0)){
		for (int u = n - 1; u != 0; u = parent[u]){
			graph[parent[u]][u] -= 1;
			graph[u][parent[u]] += 1;
		}
	}

	for (int i = 0; i < n; i++){
		if (!visited[i])
			continue;
		for (int j = 0; j < n; j++){
			if (visited[j] || graph[j][i] != 2)
				continue;
			ans.push_back({i, j});
		}
	}

	// output
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	return 0;
}
