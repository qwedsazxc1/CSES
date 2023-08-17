#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;

const int maxn = 200;

struct edge{
	int v, rev;
	ll cost, flow;
};
vector<edge> graph[2 * maxn + 2];

void add_edge(int u, int v, ll cost){
	graph[u].push_back({v, (int)graph[v].size(), cost, 1});
	graph[v].push_back({u, (int)graph[u].size() - 1, -cost, 0});
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		add_edge(0, i + 1, 0);
		add_edge(n + i + 1, 2 * n + 1, 0);
		for (int j = 0; j < n; j++){
			ll cost;
			cin >> cost;
			add_edge(i + 1, n + j + 1, cost);
		}
	}
	
	vector<pair<int, int>> from(2 * n + 2);
	ll dist[2 * n + 2];
	bool in_queue[2 * n + 2];
	from[0] = {-1, -1};
	ll maxflow = 0, mincost = 0;
	while (1){
		memset(in_queue, 0, sizeof(in_queue));
		memset(dist, 0x3f, sizeof(dist));
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		in_queue[0] = true;
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			in_queue[cur] = false;
			for (int i = 0; i < graph[cur].size(); i++){
				auto next = graph[cur][i];
				if (next.flow == 0 || dist[next.v] <= dist[cur] + next.cost)
					continue;

				dist[next.v] = dist[cur] + next.cost;
				from[next.v] = {cur, i};
				if (!in_queue[next.v]){
					in_queue[next.v] = true;
					q.push(next.v);
				}
			}
		}
		if (dist[n * 2 + 1] == INF)
			break;
		ll minflow = INF;
		int cur = 2 * n + 1;
		while (from[cur].first != -1){
			int index = from[cur].second;
			cur = from[cur].first;
			minflow = min(minflow, graph[cur][index].flow);
		}

		maxflow += minflow;
		mincost += dist[2 * n + 1] * minflow;

		cur = 2 * n + 1;
		while (from[cur].first != -1){
			int index = from[cur].second, temp = from[cur].first;
			graph[temp][index].flow -= minflow;
			graph[cur][graph[temp][index].rev].flow += minflow;
			cur = temp;
		}
	}
	cout << mincost << "\n";
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < graph[i].size(); j++){
			auto next = graph[i][j];
			if (next.v == 0)
				continue;
			if (next.flow == 0){
				cout << i << " " << next.v - n << "\n";
				break;
			}
		}
	}
	return 0;
}
