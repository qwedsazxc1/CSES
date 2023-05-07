#include <bits/stdc++.h>
#define id second
#define qr first
using namespace std;

vector<vector<int>> graph;
vector<int> arr, start, e;
int c = 0;

void dfs(int cur, int prev){
	start[cur] = c;
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		c++;
		dfs(next, cur);
	}
	e[cur] = c;
}

struct binary_index_tree{
	vector<int> bit;
	int max_size;
	binary_index_tree(int n) : max_size(n),  bit(n + 1, 0){}
	void update(int k, int x){
		for (int i = k; i <= max_size; i += i & -i)
			bit[i] += x;
	}
	int query(int qr){
		int res = 0;
		for (int i = qr; i > 0; i -= i & -i)
			res += bit[i];
		return res;
	}
};

int main(){
	int n;
	cin >> n;
	graph.resize(n); arr.resize(n);
	start.resize(n); e.resize(n);
	for (auto &x: arr)
		cin >> x;
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	vector<vector<pair<int, int>>> query(n);
	vector<int> order(n);
	for (int i = 0; i < n; i++){
		int ql = start[i], qr = e[i], id = i;
		query[ql].push_back({qr, id});
		order[ql] = i;
	}
	binary_index_tree bit(n);
	map<int, int> last_index;
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--){
		if (last_index.find(arr[order[i]]) != last_index.end()){
			bit.update(last_index[arr[order[i]]], -1);
		}
		last_index[arr[order[i]]] = i + 1;
		bit.update(i + 1, 1);
		for (auto p: query[i]){
			ans[p.id] = bit.query(p.qr + 1);
		}
	}
	for (auto x: ans){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
