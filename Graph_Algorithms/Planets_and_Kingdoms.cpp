#include <iostream>
#include <vector>

using namespace std;

void dfs1(vector<vector<int>> &graph, int node, int &end, vector<bool> &visited, vector<int> &order){
	if (visited[node])
		return;
	visited[node] = true;
	for (auto x: graph[node]){
		dfs1(graph, x, end, visited, order);
	}
	order[end++] = node;
}

void dfs2(vector<vector<int>> &graph, int node, int g, vector<bool> &visited, vector<int> &group){
	if (visited[node])
		return;
	visited[node] = true;
	for (auto x: graph[node])
		dfs2(graph, x, g, visited, group);
	group[node] = g;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n), reverse_graph(n);
	vector<bool> visited(n);
	vector<int> order(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		reverse_graph[v].push_back(u);
	}
	int end = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs1(graph, i, end, visited, order);
	vector<int> group(n);
	visited.assign(n, 0);
	int g = 1;
	for (int i = n - 1; i >= 0; i--){
		if (!visited[order[i]])
			dfs2(reverse_graph, order[i], g++, visited, group);
	}
	cout << --g << "\n";
	for (int i = 0; i < n; i++)
		cout << group[i] << " ";
	cout << "\n";
	return 0;
}
