#include <iostream>
#include <vector>

using namespace std;

vector<int> in, out, order_node;
vector<vector<int>> graph;
vector<long long> tree, node_value;
int times = -1;

void dfs(int cur, int prev){
	in[cur] = ++times;
	order_node[times] = cur;
	for (auto c: graph[cur]){
		if (c == prev)
			continue;
		dfs(c, cur);
	}
	out[cur] = times;
}

long long update(int node, int l, int r, int k){
	if (k > r || k < l)
		return tree[node];
	if (l == r)
		return tree[node] = node_value[order_node[k]];
	int mid = (r - l) / 2 + l;
	return tree[node] = update(2 * node + 1, l, mid, k) + update(2 * node + 2, mid + 1, r, k);
}

long long query(int node, int l, int r, int ql, int qr){
	if (l > qr || r < ql)
		return 0;
	if (l >= ql && r <= qr)
		return tree[node];
	int mid = (r - l) / 2 + l;
	return query(node * 2 + 1, l, mid, ql, qr) + query(node * 2 + 2, mid + 1, r, ql, qr);
}

int main(){
	int n, q;
	cin >> n >> q;
	node_value.resize(n);
	order_node.resize(n);
	tree.assign(n << 2, 0);
	in.resize(n);
	out.resize(n);
	for (int i = 0; i < n; i++){
		long long value;
		cin >> value;
		node_value[i] = value;
	}
	graph.resize(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++)
		update(0, 0, n - 1, i);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int s, x;
			cin >> s >> x;
			s--;
			node_value[s] = x;
			update(0, 0, n - 1, in[s]);
		}
		else{
			int s;
			cin >> s;
			s--;
			cout << query(0, 0, n - 1, in[s], out[s]) << "\n";
		}
	}
	return 0;
}
