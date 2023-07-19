#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans = 0;
int n;
vector<vector<ll>> graph;
vector<int> p;
vector<bool> visited;

bool bfs(int node){
	visited.assign(n, false);
	queue<int> q;
	q.push(node);
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < n; i++){
			if (!graph[f][i] || visited[i])
				continue;
			visited[i] = true;
			q.push(i);
			p[i] = f;
		}
	
	}
	return visited[n - 1];
}

int main(){
	int m;
	cin >> n >> m;
	graph.assign(n, vector<ll>(n, 0));
	p.resize(n);
	visited.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u][v] += w;
	}
	while (bfs(0)){
		ll max_flow = 1e18;
		for (int u = n - 1; u != 0; u = p[u]){
			max_flow = min(max_flow, graph[p[u]][u]);
		}
		ans += max_flow;
		for (int u = n - 1; u != 0; u = p[u]){
			graph[p[u]][u] -= max_flow;
			graph[u][p[u]] += max_flow;
		}
	}
	cout << ans << "\n";
	return 0;
}
