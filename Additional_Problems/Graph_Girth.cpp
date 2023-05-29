#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f

vector<vector<int>> graph;
vector<int> dist;

int bfs(int start){
	int res = INF;
	dist.assign(graph.size(), -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (auto next: graph[f]){
			if (dist[next] == -1){
				q.push(next);
				dist[next] = dist[f] + 1;
			}
			else if (dist[next] >= dist[f])
				res = min(res, dist[f] + dist[next] + 1);
		}
	}
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	int ans = INF;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++){
		ans = min(bfs(i), ans);
	}
	if (ans == INF)
		ans = -1;
	cout << ans << "\n";
	return 0;
}
