#include <bits/stdc++.h>

using namespace std;

struct edge{
	int u, v;
};

vector<edge> elist;
vector<vector<int>> graph;
vector<int> visit, low, group;
int t = 1, group_amount = 0;
stack<int> s;

void dfs(int cur, int prev){
	visit[cur] = low[cur] = t++;
	s.push(cur);
	for (auto next: graph[cur]){
		if (!visit[next])
			dfs(next, cur);
		if (prev == next)
			continue;
		low[cur] = min(low[cur], low[next]);
	}
	if (visit[cur] == low[cur]){
		int node;
		do {
			node = s.top();
			s.pop();
			group[node] = group_amount;

		} while (node != cur);
		group_amount++;
	}
}



int main(){
	int n, m;
	cin >> n >> m;
	elist.resize(m);
	graph.resize(n);
	visit.assign(n, 0);
	low.assign(n, 0);
	group.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		elist[i] = (edge){u, v};
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!visit[i])
			dfs(i, i);
	vector<edge> ans;
	ans.reserve(m);
	for (int i = 0; i < m; i++){
		int u = elist[i].u, v = elist[i].v;
		if (group[u] != group[v]){
			ans.push_back({u + 1, v + 1});
		}
	}
	cout << ans.size() << "\n";
	for (edge e: ans)
		cout << e.u << " " << e.v << "\n";
	return 0;
}
