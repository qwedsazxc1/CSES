#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<bool> &visited, int node, vector<int> &path, vector<int> &succ){
	stack<int> s;
	s.push(node);
	while (!s.empty()){
		int t = s.top();
		s.pop();
		path.push_back(t);
		if (!visited[t])
			s.push(succ[t]);
		visited[t] = true;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> succ(n);
	for (int i = 0; i < n; i++){
		cin >> succ[i];
		succ[i]--;
	}
	vector<bool> visited(n, false);
	vector<int> length(n, 0), path;
	path.reserve(n);
	for (int i = 0; i < n; i++){
		if (visited[i])
			continue;
		dfs(visited, i, path, succ);
		int last = path[path.size() - 1];
		if (length[last] == 0){
			int j = 0;
			for (; j < path.size(); j++){
				if (last == path[j])
					break;
			}
			int cy_length = path.size() - 1 - j;
			length[last] = cy_length;
			path.pop_back();
			while (path[path.size() - 1] != last){
				length[path[path.size() - 1]] = cy_length;
				path.pop_back();
			}
		}
		int l = length[last], j = 1;
		path.pop_back();
		while (!path.empty()){
			length[path[path.size() - 1]] = l + j;
			path.pop_back();
			j++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << length[i] << " ";
	cout << "\n";
	return 0;
}
