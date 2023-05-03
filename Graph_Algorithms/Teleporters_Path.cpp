#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> degree(n, 0), in_degree(n, 0), out_degree(n, 0);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[v].push_back(u);
		degree[v]++;
		in_degree[v]++;
		out_degree[u]++;
	}
	for (int i = 0; i < n; i++){
		if (i == 0){
			if (in_degree[i] != out_degree[i] - 1){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			continue;
		}
		if (i == n - 1){
			if (in_degree[i] - 1 != out_degree[i]){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			continue;
		}
		if (in_degree[i] != out_degree[i]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	vector<int> ans;
	ans.reserve(m + 1);
	stack<int> s;
	s.push(n - 1);
	while (!s.empty()){
		int node = s.top();
		if (degree[node] == 0){
			s.pop();
			ans.push_back(node);
			continue;
		}
		degree[node]--;
		s.push(graph[node].back());
		graph[node].pop_back();
	}
	if (ans.size() != m + 1){
		cout << "IMPOSSIBLE\n";
	}
	else{
		for (auto e: ans)
			cout << e + 1 << " ";
		cout << "\n";
	}
	return 0;
}
