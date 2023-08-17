#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;

const int maxn = 505;

struct edge{
	int v, rev;
	ll cost, flow;
	bool oridir;
};

vector<edge> graph[maxn];

void add_edge(int u, int v, ll cost){
	graph[u].push_back({v, (int)graph[v].size(), cost, 1, true});
	graph[v].push_back({u, (int)graph[u].size() - 1, -cost, 0, false});
}

bool DFS(vector<int> &ans, int cur, int target){
	ans.push_back(cur);
	if (cur == target)
		return true;
	for (auto &next: graph[cur]){
		if (next.flow || !next.oridir)
			continue;
		next.flow = 1;
		if (DFS(ans, next.v, target));
			return true;
		next.flow =	0;
	}
	ans.pop_back();
	return false;
}

int main(){
	int n, m;
	ll k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		add_edge(u, v, 1);
	}

	ll maxflow = 0, mincost = 0;
	bool in_queue[n];
	int dist[n];
	pair<int, int> from[n];
	from[0] = {-1, -1};
	while (1){
		memset(in_queue, 0, sizeof(in_queue));
		memset(dist, INF, sizeof(dist));
		dist[0] = 0;
		queue<int> q;
		in_queue[0] = true;
		q.push(0);
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
		if (dist[n - 1] == INF)
			break;
		ll minflow = INF;
		int cur = n - 1;
		while (from[cur].first != -1){
			int index = from[cur].second;
			cur = from[cur].first;
			minflow = min(minflow, graph[cur][index].flow);
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
		if (maxflow == k)
			break;
	}
	if (maxflow < k)
		cout << "-1\n";
	else{
		cout << mincost << "\n";
		for (int i = 0; i < maxflow; i++){
			vector<int> ans;
			DFS(ans, 0, n - 1);
			cout << ans.size() << "\n";
			for (auto e: ans)
				cout << e + 1 << " ";
			cout << "\n";
		}
	}
	return 0;
}
