#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e4 * 5;
bitset<maxn> ans[maxn];
vector<int> group, order;
vector<vector<int>> graph, reverse_graph;
int t = 0, group_size = 0;

void dfs1(int cur){
	group[cur] = 1;
	for (auto next: graph[cur])
		if (group[next] == 0)
			dfs1(next);
	
	order[t++] = cur;
}

void dfs2(int cur){
	group[cur] = group_size;
	for (auto next: reverse_graph[cur])
		if (group[next] == -1)
			dfs2(next);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	graph.resize(n); reverse_graph.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		reverse_graph[v].push_back(u);
	}
	order.assign(n, 0); group.assign(n, 0);
	for (int i = 0; i < n; i++)
		if (group[i] == 0)
			dfs1(i);
	group.assign(n, -1);
	for (int i = n - 1; i >= 0; i--)
		if (group[order[i]] == -1){
			dfs2(order[i]);
			group_size++;
		}
	vector<vector<int>> new_graph(group_size);
	vector<int> outdegree(group_size, 0);
	for (int i = 0; i < n; i++){
		for (auto next: graph[i]){
			if (group[i] == group[next])
				continue;
			new_graph[group[next]].push_back(group[i]);
			outdegree[group[i]]++;
		}
	}

	queue<int> que;
	for (int i = 0; i < group_size; i++){
		if (outdegree[i] == 0){
			que.push(i);
			ans[i].set(i);
		}
	}
	while (!que.empty()){
		int f = que.front();
		que.pop();
		for (auto next: new_graph[f]){
			ans[next] |= ans[f];
			outdegree[next]--;
			if (outdegree[next] == 0){
				ans[next].set(next);
				que.push(next);
			}
		}
	}

	while (q--){
		int u, v;
		cin >> u >> v;
		u--; v--;
		u = group[u]; v = group[v];
		if (ans[u][v])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
