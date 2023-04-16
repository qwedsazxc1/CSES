#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<vector<int>> parent(n, vector<int>(20));
	vector<vector<int>> graph(n);
	vector<int> dep(n);
	parent[0][0] = 0;
	dep[0] = 1;
	
	for (int i = 0; i < n - 1; i++){
		int input;
		cin >> input;
		input--;
		parent[i + 1][0] = input;
		graph[input].push_back(i + 1);
	}
	stack<pair<int, int>> s;
	s.push({0, 1});
	while (!s.empty()){
		auto p = s.top();
		s.pop();
		dep[p.first] = p.second;
		for (int n: graph[p.first])
			s.push({n, p.second + 1});
	}
	for (int i = 1; i < 20; i++)
		for (int j = 0; j < n; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		
	
	while (q--){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (dep[a] > dep[b])
			swap(a, b);
		int step = dep[b] - dep[a], pb = b;
		for (int i = 0; i < 20; i++)
			if (1 << i & step)
				pb = parent[pb][i];
		if (pb == a){
			cout << pb + 1 << "\n";
			continue;
		}
		for (int i = 19; i >= 0; i--){
			if (parent[pb][i] == parent[a][i])
				continue;
			pb = parent[pb][i];
			a = parent[a][i];
		}
		a = parent[a][0];
		cout << a + 1 << "\n";
	}
	return 0;
}
