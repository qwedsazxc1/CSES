#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, long long>>> graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v, w});
	}

	vector<vector<long long>> dis(n);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push({0, 0});
	while (!q.empty()){
		auto p = q.top();
		q.pop();
		int cur = p.second;
		if (dis[cur].size() >= k)
			continue;
		long long w = p.first;
		dis[cur].push_back(w);
		for (auto neighbor: graph[cur]){
			q.push({w + neighbor.second, neighbor.first});
		}
	}
	for (long long d: dis[n - 1])
		cout << d << " ";
	cout << "\n";
	return 0;
}
