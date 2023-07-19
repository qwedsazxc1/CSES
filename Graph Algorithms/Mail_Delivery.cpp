#include <bits/stdc++.h>

using namespace std;

vector<unordered_map<int, int>> graph;

struct union_and_find{
	int size = 0, n;
	vector<int> parent, sz;
	int find(int a){
		if (parent[a] == a)
			return a;
		return parent[a] = find(parent[a]);
	}
	void _union(int a, int b){
		int a_boss = find(a), b_boss = find(b);
		if (a_boss == b_boss)
			return;
		if (sz[a_boss] > sz[b_boss])
			swap(a_boss, b_boss);
		parent[a_boss] = b_boss;
		sz[b_boss] += sz[a_boss];
	}
	union_and_find(int n){
		this->n = n;
		size = n;
		parent.resize(n);
		sz.assign(n, 1);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	bool test(){
		int p_of0 = find(0);
		for (int i = 0; i < n; i++){
			if (p_of0 == i)
				continue;
			if (parent[i] == i && sz[i] != 1)
				return true;
		}
		return false;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	union_and_find dsu(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u][v];
		graph[v][u];
		dsu._union(u, v);
	}
	int odd_count = 0;
	vector<int> degree(n, 0);
	for (int i = 0; i < n; i++){
		if (graph[i].size() & 1)
			odd_count++;
		
		degree[i] = graph[i].size();
	}
	if (odd_count != 0 || dsu.test()){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int start = 0;
	vector<int> ans;
	ans.reserve(m + 1);
	stack<int> s;
	s.push(start);
	while (!s.empty()){
		int node = s.top();
		if (degree[node] == 0){
			s.pop();
			ans.push_back(node);
		}
		else{
			int n = (*graph[node].begin()).first;
			degree[node]--;
			degree[n]--;
			graph[node].erase(n);
			graph[n].erase(node);
			s.push(n);
		}
	}
	for (auto a: ans)
		cout << a + 1 << " ";
	cout << "\n";
	return 0;
}
