#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> &order, vector<vector<int>> &graph){
	if (visited[node])
		return;
	visited[node] = true;
	for (auto n: graph[node]){
		dfs(n, visited, order, graph);
	}
	order.push_back(node);
}

void dfs2(int node, vector<int> &group, vector<vector<int>> &graph, int group_num){
	if (group[node] != -1)
		return;
	group[node] = group_num;
	for (auto n: graph[node]){
		dfs2(n, group, graph, group_num);
	}
}

int main(){
	int n, m;
	cin >> m >> n;
	vector<vector<int>> graph(2 * n), reverse_graph(2 * n);
	for (int i = 0; i < m; i++){
		int u, v;
		char fc, sc;
		cin >> fc >> u >> sc >> v;
		u--; v--;
		if (fc == '-')
			u += n;
		if (sc == '-')
			v += n;
		graph[(u + n) % (2 * n)].push_back(v);
		reverse_graph[v].push_back((u + n) % (2 * n));
		graph[(v + n) % (2 * n)].push_back(u);
		reverse_graph[u].push_back((v + n) % (2 * n));
	}

	vector<int> group(2 * n, -1), order;
	vector<bool> visited(2 * n, false);
	order.reserve(2 * n);
	for (int i = 0; i < 2 * n; i++){
		if (!visited[i])
			dfs(i, visited, order, graph);
	}
	int group_num = 0;
	for (int i = 2 * n - 1; i >= 0; i--){
		if (group[order[i]] == -1)
			dfs2(order[i], group, reverse_graph, group_num++);
	}
	bool flag = false;
	for (int i = 0; i < n; i++){
		if (group[i] == group[i + n]){
			flag = true;
			break;
		}
	}
	if (flag){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<vector<int>> new_graph(group_num), ori_node(group_num);
	vector<int> indegree(group_num, 0);
	for (int i = 0; i < 2 * n; i++){
		for (auto n: reverse_graph[i]){
			if (group[n] == group[i])
				continue;
			new_graph[group[i]].push_back(group[n]);
			indegree[group[n]]++;
		}
		ori_node[group[i]].push_back(i);
	}
	vector<int> ans(n, 0);
	queue<int> q;
	for (int i = 0; i < group_num; i++)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty()){
		int node = q.front();
		q.pop();
		for (auto m: ori_node[node]){
			if (ans[m % n] != 0)
				continue;
			if (m >= n)
				ans[m - n] = 2;
			else
				ans[m] = 1;
		}
		for (auto n: new_graph[node]){
			indegree[n]--;
			if (indegree[n] == 0)
				q.push(n);
		}
	}
	for (int i = 0; i < n; i++)
		if (ans[i] == 1)
			cout << "+ ";
		else
			cout << "- ";
	cout << "\n";
	return 0;
}
