#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans = 0;
const int maxn = 500;
int n;

struct edge{
	int v;
	ll w;
	int rev_idx;
};
vector<edge> graph[maxn];
int p[maxn], idx[maxn];
bool visited[maxn];

bool bfs(int node){
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(node);
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < graph[f].size(); i++){
			int next = graph[f][i].v;
			if (visited[next] || graph[f][i].w == 0)
				continue;
			visited[next] = true;
			q.push(next);
			p[next] = f;
			idx[next] = i;
		}
	
	}
	return visited[n - 1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v, w, (int)graph[v].size()});
		graph[v].push_back({u, 0, (int)graph[u].size() - 1});
	}
	while (bfs(0)){
		ll max_flow = 1e18;
		for (int u = n - 1; u != 0; u = p[u]){
			max_flow = min(max_flow, graph[p[u]][idx[u]].w);
		}
		ans += max_flow;
		for (int u = n - 1; u != 0; u = p[u]){
			graph[p[u]][idx[u]].w -= max_flow;
			graph[u][graph[p[u]][idx[u]].rev_idx].w += max_flow;
		}
	}
	cout << ans << "\n";
	return 0;
}
