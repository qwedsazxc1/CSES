#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int node_amount;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> p;

bool bfs(int node){
	queue<int> q;
	q.push(node);
	visited.assign(node_amount, false);
	visited[node] = true;
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < node_amount; i++){
			if (!graph[f][i] || visited[i])
				continue;
			visited[i] = true;
			q.push(i);
			p[i] = f;
		}
	}
	return visited[node_amount - 1];
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	node_amount = n + m + 2;
	graph.assign(node_amount, vector<int>(node_amount, 0));
	p.resize(node_amount);
	for (int i = 0; i < k; i++){
		int u, v;
		cin >> u >> v;
		graph[u][v + n] += 1;
	}
	for (int i = 1; i <= n; i++){
		graph[0][i] += 1;
	}
	for (int i = 1; i <= m; i++){
		graph[i + n][node_amount - 1] += 1;
	}
	vector<pair<int, int>> ans;
	while (bfs(0)){
		for (int u = node_amount - 1; u != 0; u = p[u]){
			graph[p[u]][u] -= 1;
			graph[u][p[u]] += 1;
		}
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = n + 1; j < node_amount; j++){
			if (!graph[j][i])
				continue;
			ans.push_back({i, j});
		}
	}
	cout << ans.size() << "\n";
	for (auto p: ans)
		cout << p.first << " " << p.second - n << "\n";
	return 0;
}
