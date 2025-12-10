#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> isap(n), id(n);
	vector<vector<int>> ngraph;
	auto bcc = [&]() -> void {
		vector<int> low(n), dfn(n, -1);
		int cnt = 0;
		stack<int> s;
		auto dfs = [&](auto &self, int cur, int prev) -> void {
			low[cur] = dfn[cur] = cnt++;
			int soncnt = 0;
			for (auto next: graph[cur]){
				if (prev == next)
					continue;
				if (dfn[next] != -1){
					low[cur] = min(low[cur], dfn[next]);
				}
				else{
					self(self, next, cur);
					soncnt++;
					low[cur] = min(low[cur], low[next]);
					if ((cur == 0 && soncnt >= 2) || (cur != 0)){
						isap[cur] = 1;
					}
				}
			}
			if (cur == 0 && soncnt >= 2){
				isap[cur] = 1;
			}
		}
	};
}
