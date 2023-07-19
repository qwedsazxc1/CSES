#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	vector<int> degree(n, 0);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (degree[i] == 1)
			q.push(i);
	int count = 0;
	while (!q.empty()){
		int node = q.front();
		q.pop();
		if (degree[node] == 0)
			continue;
		count++;
		degree[node] = 0;
		for (auto c: graph[node]){
			if (degree[c] == 0)
				continue;
			degree[c] = 0;
			for (auto nei: graph[c]){
				if (degree[nei] == 0)
					continue;
				degree[nei]--;
				if (degree[nei] == 1)
					q.push(nei);
			}
		}
	}
	cout << count << "\n";
	return 0;
}
