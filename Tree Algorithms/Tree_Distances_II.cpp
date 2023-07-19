#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<long long> dis, sz;
int n;

long long dfs(int cur, int prev){
	long long s = 1;
	dis[cur] = 0;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		s += dfs(next, cur);
		dis[cur] += dis[next] + sz[next];
	}
	return sz[cur] = s;
}

void dfs2(int cur, int prev){
	for (auto next: graph[cur]){
		if (prev == next)
			continue;
		dis[next] = dis[cur] + sz[cur] - 2 * sz[next];
		sz[next] = n;
		dfs2(next, cur);
	}
}

int main(){
	cin >> n;
	graph.resize(n); dis.assign(n, 0);
	sz.assign(n, 0);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	dfs2(0, 0);
	for (int i = 0; i < n; i++)
		cout << dis[i] << " ";
	cout << "\n";
	return 0;
}
