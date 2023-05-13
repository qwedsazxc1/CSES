#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> parent;


bool bfs(int node = 0){
	queue<int> q;
	q.push(node);
	visited.assign(n, false);
	visited[node] = true;
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

bool dfs(int node, vector<int> &path){
	if (visited[node])
		return false;
	visited[node] = true;
	path.push_back(node);
	if (node == 0)
		return true;
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (graph[node][i])
			if (flag = dfs(i, path))
				break;
	}
	if (!flag){
		path.pop_back();
		visited[node] = false;
	}
	return flag;
}

int main(){
	int m;
	cin >> n >> m;
	graph.assign(n, vector<int> (n, 0));
	parent.resize(n);
	vector<vector<int>> ori_graph(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u][v] = 1;
		ori_graph[u][v] = 1;
	}
	int max_flow = 0;
	while (bfs()){
		max_flow++;
		for (int u = n - 1; u != 0; u = parent[u]){
			graph[parent[u]][u] -= 1;
			graph[u][parent[u]] += 1;
		}
	}
	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < n; j++){
			if (ori_graph[i][j] && graph[i][j])
				graph[i][j] -= 1;
		}
	vector<vector<int>> ans(max_flow);
	for (int i = 0; i < max_flow; i++){
		int start = n - 1;
		visited.assign(n, false);
		dfs(n - 1, ans[i]);
		for (int j = 0; j < ans[i].size() - 1; j++)
			graph[ans[i][j]][ans[i][j + 1]] = 0;
	}

	cout << ans.size() << "\n";
	for (auto &v: ans){
		cout << v.size() << "\n";
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i] + 1 << " ";
		cout << "\n";
	}
	return 0;
}
