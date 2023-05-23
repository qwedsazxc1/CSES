#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> outdegree(n, 0);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[v].push_back(u);
		outdegree[u]++;
	}
	priority_queue<int> pq;
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		if (outdegree[i] == 0)
			pq.push(i);
	}
	int i = n - 1;
	while (!pq.empty()){
		int node = pq.top();
		pq.pop();
		ans[i--] = node;
		for (auto next: graph[node]){
			outdegree[next]--;
			if (outdegree[next] == 0)
				pq.push(next);
		}
	}
	for (auto e: ans)
		cout << e + 1 << " ";
	cout << "\n";
	return 0;
}
