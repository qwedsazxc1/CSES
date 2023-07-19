#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<long long> cnt;
vector<bool> proccessed;
vector<int> subtree_size;
long long ans = 0, k, max_depth = -1;

int dfs(int cur, int prev){
	subtree_size[cur] = 1;
	for (auto next: graph[cur]){
		if (prev == next || proccessed[next])
			continue;
		subtree_size[cur] += dfs(next, cur);
	}
	return subtree_size[cur];
}

int find_centroid(int cur, int prev, int target_size){
	for (auto next: graph[cur]){
		if (proccessed[next] || next == prev || subtree_size[next] < target_size)
			continue;
		return find_centroid(next, cur, target_size);
	}
	return cur;
}

void add_cnt(int cur, int prev, bool filled, int depth = 1){
	if (depth > k)
		return;
	max_depth = max((long long)depth, max_depth);
	if (filled){
		cnt[depth] += 1;
	}
	else{
		ans += cnt[k - depth];
	}
	for (auto next: graph[cur]){
		if (prev == next || proccessed[next])
			continue;
		add_cnt(next, cur, filled, depth + 1);
	}
}

void centroid_decomposition(int node){
	int centroid = find_centroid(node, node, dfs(node, node) / 2);
	proccessed[centroid] = true;
	for (auto next: graph[centroid]){
		if (proccessed[next])
			continue;
		add_cnt(next, next, false);
		add_cnt(next, next, true);
	}
	for (int i = 1; i <= max_depth; i++)
		cnt[i] = 0;
	max_depth = -1;
	for (auto next: graph[centroid]){
		if (proccessed[next])
			continue;
		centroid_decomposition(next);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> k;
	graph.resize(n);
	cnt.assign(k + 1, 0);
	proccessed.assign(n, false);
	subtree_size.resize(n);
	cnt[0] = 1;
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	centroid_decomposition(0);
	cout << ans << "\n";
	return 0;
}
