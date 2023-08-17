#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;

const int maxn = 505;

struct edge{
	int v, rev;
	long long cost, flow;
};

long long dist[maxn];
vector<edge> graph[maxn];

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int u, v;
		ll cost, flow;
		cin >> u >> v >> flow >> cost;
		u--; v--;
		graph[u].push_back({v, (int)graph[v].size(), cost, flow});
		graph[v].push_back({u, (int)graph[u].size() - 1, -cost, 0});
	}

	ll maxflow = 0, mincost = 0;
	vector<pair<int, int>> from(n);
	from[0] = {-1, -1};
	bool in_queue[n];
	while (1){
		memset(dist, 0x3f, sizeof(dist));
		memset(in_queue, 0, sizeof(in_queue));
		queue<int> q;
		q.push(0);
		in_queue[0] = true;
		dist[0] = 0;
		while (!q.empty()){
			int u = q.front();
			q.pop();
			in_queue[u] = false;
			for (int i = 0; i < graph[u].size(); i++){
				auto next = graph[u][i];
				if (next.flow == 0 || dist[u] + next.cost >= dist[next.v])
					continue;
				dist[next.v] = dist[u] + next.cost;
				from[next.v] = {u, i};
				if (!in_queue[next.v]){
					q.push(next.v);
					in_queue[next.v] = true;
				}
			}
		}
		if (dist[n - 1] == INF)
			break;
		ll minflow = INF;
		int cur = n - 1;
		while (from[cur].first != -1){
			int index = from[cur].second;
			cur = from[cur].first;
			minflow = min(minflow, graph[cur][index].flow);
		}
		if (k <= maxflow + minflow){
			mincost += (k - maxflow) * dist[n - 1];
			maxflow = k;
			break;
		}
		maxflow += minflow;
		mincost += minflow * dist[n - 1];
		cur = n - 1;
		while (from[cur].first != -1){
			int index = from[cur].second, temp = from[cur].first;
			graph[temp][index].flow -= minflow;
			graph[cur][graph[temp][index].rev].flow += minflow;
			cur = temp;
		}
	}

	if (maxflow < k)
		cout << "-1\n";
	else
		cout << mincost << "\n";
	
	return 0;
}
