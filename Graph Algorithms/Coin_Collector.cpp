#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void dfs(int node, vector<int> &order, vector<bool> &visited, vector<vector<int>> &graph){
	if (visited[node])
		return;
	visited[node] = true;
	for (auto n: graph[node]){
		dfs(n, order, visited, graph);
	}
	order.push_back(node);
}

void dfs2(int node, int group_num, vector<int> &group, vector<vector<int>> &graph){
	if (group[node] != -1)
		return;
	group[node] = group_num;
	for (auto n: graph[node])
		dfs2(n, group_num, group, graph);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<long long> coin(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	vector<vector<int>> graph(n), reverse_graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		reverse_graph[v].push_back(u);
	}
	vector<int> group(n, -1), order;
	vector<bool> visited(n, false);
	order.reserve(n);
	for (int i = 0; i < n; i++){
		if (!visited[i])
			dfs(i, order, visited, graph);
	}
	int group_num = 0;
	for (int i = n - 1; i >= 0; i--){
		if (group[order[i]] == -1)
			dfs2(order[i], group_num++, group, reverse_graph);
	}
	vector<vector<int>> new_graph(group_num);
	vector<int> indegree(group_num, 0);
	vector<long long> new_coin(group_num, 0);
	for (int i = 0; i < n; i++){
		new_coin[group[i]] += coin[i];
		for (auto n: graph[i]){
			if (group[i] == group[n])
				continue;
			new_graph[group[i]].push_back(group[n]);
		   	indegree[group[n]]++;	
		}
	}
	vector<long long> dp(group_num, 0);
	queue<int> q;
	long long res = 0;
	for (int i = 0; i < group_num; i++){
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()){
		int node = q.front();
		q.pop();
		dp[node] += new_coin[node];
		res = max(res, dp[node]);
		for (auto n: new_graph[node]){
			dp[n] = max(dp[n], dp[node]);
			indegree[n]--;
			if (indegree[n] == 0)
				q.push(n);
		}
	}
	cout << res << "\n";
	return 0;
}
