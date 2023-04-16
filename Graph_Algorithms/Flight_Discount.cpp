#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF (0x3f3f3f3f3f3f3f3f)
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long>>> graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back(make_pair(v, w));
	}
	vector<vector<long long>> dis(n, vector<long long>(2, INF));
	priority_queue<pair<pair<long long, int>, int>, vector<pair<pair<long long, int>, int>>, greater<pair<pair<long long, int>, int>>> q;
	q.push({{0, 0}, 0});
	q.push({{0, 0}, 1});
	while (!q.empty()){
		auto f = q.top();
		q.pop();
		int cur = f.first.second;
		int use = f.second;
		if (dis[cur][use] != INF)
			continue;
		long long w = f.first.first;
		dis[cur][use] = w;
		for (auto neighbor: graph[cur]){
			if (use){
				q.push({{w + neighbor.second, neighbor.first}, 1});
			}
			else{
				q.push({{w + neighbor.second, neighbor.first}, 0});
				q.push({{w + neighbor.second / 2, neighbor.first}, 1});
			}
		}
	}
	cout << dis[n - 1][1] << "\n";
	return 0;
}
