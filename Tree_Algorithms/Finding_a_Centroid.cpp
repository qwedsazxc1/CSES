#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;

vector<vector<int>> graph;

int dfs(int cur, int prev){
	int cnt = 1;
	bool flag = true;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;	
		int res = dfs(next, cur);
		if (res > n / 2)
			flag = false;
		cnt += res;
	}
 	if (n - cnt > n / 2)
		flag = false;
	if (flag)
		ans = cur;
	return cnt;
}

int main(){
	cin >> n;
	graph.resize(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	cout << ans + 1 << "\n";
	return 0;
}
