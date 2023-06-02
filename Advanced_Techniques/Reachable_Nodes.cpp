#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 * 1e4;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> outdegree(n, 0);
	bitset<maxn> ans[n];
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[v].push_back(u);
		outdegree[u]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (outdegree[i] == 0){
			q.push(i);
			ans[i].set(i);
		}
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (auto next: graph[cur]){
			outdegree[next]--;
			ans[next] |= ans[cur];
			if (outdegree[next] == 0){
				ans[next].set(next);
				q.push(next);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i].count() << " ";
	cout << "\n";
	return 0;
}
