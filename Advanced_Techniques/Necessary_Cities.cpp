#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited, low;
vector<bool> isap;
int t = 1;

void dfs(int cur, int prev){
	visited[cur] = t++;
	low[cur] = cur;
	int child = 0;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		if (!visited[next]){
			dfs(next, cur);
			child++;
			if (visited[cur] <= visited[low[next]])
				isap[cur] = true;
			if (visited[low[cur]] > visited[low[next]])
				low[cur] = low[next];
		}
		else {
			if (visited[next] < visited[low[cur]])
				low[cur] = next;
		} 
			
		
	}
	if (cur == prev){
		if (child > 1)
			isap[cur] = true;
		else
			isap[cur] = false;
	}
	
}

int main(){
	int n, m;
	cin >> n >> m;
	isap.assign(n, false);
	graph.resize(n);
	visited.assign(n, 0);
	low.resize(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i, i);


	vector<int> ans;
	ans.reserve(n);
	for (int i = 0; i < n; i++)
		if (isap[i])
			ans.push_back(i + 1);
	cout << ans.size() << "\n";
	for (auto n: ans)
		cout << n << " ";
	cout << "\n";
	return 0;
}
