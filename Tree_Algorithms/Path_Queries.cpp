#include <iostream>
#include <vector>

using namespace std;

int count = 1;

vector<vector<int>> graph;
vector<int> sz, maxson, father, id, topfather, dep;
vector<long long> value, tree;

void dfs(int cur, int prev){
	dep[cur] = dep[prev] + 1;
	maxson[cur] = 0;
	sz[cur] = 1;
	father[cur] = prev;
	for (auto n: graph[cur]){
		if (n == prev)
			continue;
		dfs(n, cur);
		sz[cur] += sz[n];
		if (sz[n] > sz[maxson[cur]])
			maxson[cur] = n;
	}
}

void dfs2(int cur, int top){
	id[cur] = count++;
	topfather[cur] = top;
	if (maxson[cur])
		dfs2(maxson[cur], top);
	for (int n: graph[cur]){
		if (n == father[cur] || n == maxson[cur])
			continue;
		dfs2(n, n);
	}
}

long long update(int node, int l, int r, int k, int x){
	if (l > k || r < k)
		return tree[node];
	if (l == r)
		return tree[node] = x;
	int mid = (r - l) / 2 + l;
	return tree[node] = update(node * 2 + 1, l, mid, k, x) + update(node * 2 + 2, mid + 1, r, k, x);
}

long long query(int node, int l, int r, int ql, int qr){
	if (ql > r || l > qr)
		return 0;
	if (l >= ql && r <= qr)
		return tree[node];
	int mid = (r - l) / 2 + l;
	return query(node * 2 + 1, l, mid, ql, qr) + query(node * 2 + 2, mid + 1, r, ql, qr);
}

int main(){
	int n, q;
	cin >> n >> q;
	graph.resize(n + 1);
	sz.resize(n + 1);
	father.resize(n + 1);
	id.resize(n + 1);
	topfather.resize(n + 1);
	dep.resize(n + 1);
	value.resize(n + 1);
	maxson.resize(n + 1);
	tree.assign((n + 1) << 2, 0);
	for (int i = 0; i < n; i++){
		long long input;
		cin >> input;
		value[i + 1] = input;
	}
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 1);
	for (int i = 0; i < n; i++)
		update(0, 1, n, id[i + 1], value[i + 1]);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int s;
			long long x;
			cin >> s >> x;
			value[s] = x;
			update(0, 1, n, id[s], x);
		}
		else{
			int s;
			cin >> s;
			long long res = 0;
			while (1 != topfather[s]){
				res += query(0, 1, n, id[topfather[s]], id[s]);
				s = father[topfather[s]];
			}
			cout << res + query(0, 1, n, id[1], id[s]) << "\n";
		}
	}
	return 0;
}
