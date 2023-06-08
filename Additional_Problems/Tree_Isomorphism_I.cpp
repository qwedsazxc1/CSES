#include <bits/stdc++.h>
#define node first.first
#define parent first.second

using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> graph1, graph2;
int t = 0;
map<vector<int>, int> m;

int dfs(int cur, int prev, vector<vector<int>> &graph){
	vector<int> v;
	for (auto next: graph[cur]){
		if (prev == next)
			continue;
		v.push_back(dfs(next, cur, graph));
	}
	sort(v.begin(), v.end());
	if (m.find(v) == m.end()) m[v] = t++;
	return m[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		graph1.assign(n, vector<int>());
		graph2.assign(n, vector<int>());
		for (int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			graph1[u].push_back(v);
			graph1[v].push_back(u);
		}
		for (int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			graph2[u].push_back(v);
			graph2[v].push_back(u);
		}
		int a = dfs(0, 0, graph1);
		int b = dfs(0, 0, graph2);
		if (a == b){
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}
