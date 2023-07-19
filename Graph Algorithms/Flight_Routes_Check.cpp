#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited){
	if (visited[node])
		return;
	visited[node] = true;
	for (auto x: graph[node])
		dfs(graph, x, visited);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n), inverse_graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		inverse_graph[v].push_back(u);
	}
	vector<bool> visited(n, false);
	dfs(graph, 0, visited);
	for (int i = 0; i < n; i++){
		if (!visited[i]){
			cout << "NO\n";
			cout << "1 " << i + 1 << "\n";
		   	return 0;	
		}
	}
	visited.assign(n, false);
	dfs(inverse_graph, 0, visited);
	for (int i = 0; i < n; i++){
		if (!visited[i]){
			cout << "NO\n";
			cout << i + 1 << " 1\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;

}
