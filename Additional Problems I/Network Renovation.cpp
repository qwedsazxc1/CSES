#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;

vector<int> graph[N];
vector<int> leaf;

void dfs(int cur, int prev){
	int cnt = 0;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		dfs(next, cur);
		cnt++;
	}
	if (cnt == 0 || (cur == 0 && cnt == 1))
		leaf.push_back(cur);
}

struct edge{
	int u, v;
};

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	vector<edge> ans;
	for (int i = 0; i < (leaf.size() + 1) / 2; i++)
		ans.push_back({leaf[i], leaf[leaf.size() / 2 + i]});
	
	cout << ans.size() << "\n";
	for (auto p: ans){
		cout << p.u + 1 << " " << p.v + 1 << "\n";
	}
	return 0;
}
