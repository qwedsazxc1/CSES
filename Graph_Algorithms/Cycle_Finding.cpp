#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

struct edge{
	int u, v;
	long long w;
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<edge> elist(m);
	for (int i = 0; i < m; i++){
		int u, v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		elist[i] = (edge){u, v, w};
	}
	int end = 0;
	vector<long long> dist(n, INF);
	vector<int> from(n);
	dist[0] = 0;
	// Bellman Ford
	for (int i = 0; i < n && end != -1; i++){
		end = -1;
		for (int j = 0; j < m; j++){
			// relax
			int u = elist[j].u, v = elist[j].v;
			long long w = elist[j].w;
			if (dist[v] > dist[u] + w){
				end = v;
				from[v] = u;
				dist[v] = dist[u] + w;
			}
		}
	}
	if (end == -1){
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		end = from[end];
	vector<int> cycle;
	cycle.reserve(n);
	for (int cur = end; ; cur = from[cur]){
		cycle.push_back(cur);
		if (cur == end && cycle.size() != 1)
			break;
	}

	cout << "YES\n";
	for (int i = (int)cycle.size() - 1; i >= 0; i--){
		cout << cycle[i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}
