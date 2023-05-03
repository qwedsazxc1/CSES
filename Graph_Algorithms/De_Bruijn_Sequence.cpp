#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

int main(){
	int n;
	cin >> n;
	if (n == 1){
		cout << "10\n";
		return 0;
	}
	graph.resize(1 << (n - 1));
	vector<map<int, int>> temp_graph(1 << (n - 1));
	vector<int> degree(1 << (n - 1));
	for (int i = 0; i < (1 << (n - 1)); i++){
		temp_graph[i][(i << 1) % (1 << (n - 1))] = 1;
		temp_graph[i][((i << 1) % (1 << (n - 1))) | 1] = 1;
		degree[i] = 2;
	}
	stack<int> s;
	vector<int> ans;
	s.push(0);
	while (!s.empty()){
		int node = s.top();
		if (degree[node] == 0){
			s.pop();
			ans.push_back(node & 1);
			continue;
		}
		auto it = temp_graph[node].begin();
		s.push((*it).first);
		degree[node] -= 1;
		temp_graph[node].erase(it);
	}
	
	for (auto e: ans)
		cout << e;
	for (int i = 3; i <= n; i++)
		cout << 0;
	cout << "\n";
}
