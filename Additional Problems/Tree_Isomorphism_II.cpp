#include <bits/stdc++.h>

using namespace std;
map<vector<int>, int> m;
int t = 0;

int sizedfs(int cur, int prev, vector<int> &centroid, vector<vector<int>> &graph){
	int sz = 1;
	bool cen = true;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		int subsize = sizedfs(next, cur, centroid, graph);
		if (subsize > graph.size() / 2)
			cen = false;
		sz += subsize;
	}
	if (graph.size() - sz > graph.size() / 2)
		cen = false;
	if (cen)
		centroid.push_back(cur);
	return sz;
}

vector<int> find_centroid(vector<vector<int>> &graph, int init = 0){
	vector<int> centroid;
	sizedfs(init, init, centroid, graph);
	return centroid;
}

int isodfs(int cur, int prev, vector<vector<int>> &graph){
	vector<int> v;
	for (auto next: graph[cur]){
		if (prev == next)
			continue;
		v.push_back(isodfs(next, cur, graph));
	}
	sort(v.begin(), v.end());
	if (m.find(v) == m.end())
		m[v] = t++;
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
		vector<vector<int>> graph1(n), graph2(n);
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
		vector<int> centroid1 = find_centroid(graph1), centroid2 = find_centroid(graph2);
		int id1 = isodfs(centroid1[0], centroid1[0], graph1), id2;
		bool flag = false;
		for (auto x: centroid2){
			id2 = isodfs(x, x, graph2);
			if (id1 == id2){
				flag = true;
				break;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}
