#include <iostream>
#include <vector>

using namespace std;

int count = 0;
vector<vector<int>> graph;
vector<long long> tree, value;
vector<int> sz, parent, topparent, maxson, id, dep;
vector<vector<int>> p(20);

long long update(int node, int l, int r, int k, int x){
	if (l > k || r < k)
		return tree[node];
	if (l == r)
		return tree[node] = x;
	int mid = (r - l) / 2 + l;
	return tree[node] = max(update(node * 2 + 1, l, mid, k, x), update(node * 2 + 2, mid + 1, r, k, x));
}

long long query(int node, int l, int r, int ql, int qr){
	if (qr < l || ql > r)
		return 0;
	if (r <= qr && l >= ql)
		return tree[node];
	int mid = (r - l) / 2 + l;
	return max(query(node * 2 + 1, l, mid, ql, qr), query(node * 2 + 2, mid + 1, r, ql, qr));
}

void dfs(int cur, int prev){
	sz[cur] = 1;
	parent[cur] = prev;
	p[0][cur] = prev;
	maxson[cur] = -1;
	dep[cur] = dep[prev] + 1;
	for (auto n: graph[cur]){
		if (n == prev)
			continue;
		dfs(n, cur);
		sz[cur] += sz[n];
		if (maxson[cur] == -1 || sz[n] > sz[maxson[cur]])
			maxson[cur] = n;
	}
}

void dfs2(int cur, int top){
	topparent[cur] = top;
	id[cur] = count++;
	if (maxson[cur] != -1)
		dfs2(maxson[cur], top);

	for (auto n: graph[cur]){
		if (n == maxson[cur] || n == parent[cur])
			continue;
		dfs2(n, n);
	}
}

int lca(int a, int b){
	if (dep[b] > dep[a])
		swap(a, b);
	int step = dep[a] - dep[b];
	for (int i = 19; i >= 0; i--){
		if (step & (1 << i))
			a = p[i][a];
	}
	if (a == b)
		return a;
	for (int i = 19; i >= 0; i--){
		if (p[i][a] == p[i][b])
			continue;
		a = p[i][a];
		b = p[i][b];
	}
	return p[0][a];
}

void init_p(){
	for (int i = 1; i < p.size(); i++)
		for (int j = 0; j < p[i].size(); j++)
			p[i][j] = p[i - 1][p[i - 1][j]];
}

long long path(int chi, int par, int n){
	long long res = 0;
	while (chi != par){
		if (topparent[chi] == chi){
			res = max(res, value[chi]);
			chi = parent[chi];
			continue;
		}
		if (dep[topparent[chi]] > dep[par]){
			res = max(res, query(0, 0, n - 1, id[topparent[chi]], id[chi]));
			chi = parent[topparent[chi]];
			continue;
		}
		res = max(res, query(0, 0, n - 1, id[par], id[chi]));
		break;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	value.resize(n);
	for (int i = 0; i < n; i++)
		cin >> value[i];
	graph.resize(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < p.size(); i++)
		p[i].resize(n);
	id.resize(n); maxson.resize(n); topparent.resize(n); sz.resize(n); parent.resize(n); dep.resize(n);
   	tree.assign(n << 2, 0);
	dep[0] = 0;
	dfs(0, 0);
	dfs2(0, 0);
	init_p();
	for (int i = 0; i < n; i++)
		update(0, 0, n - 1, id[i], value[i]);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int s;
			long long x;
			cin >> s >> x;
			s--;
			value[s] = x;
			update(0, 0, n - 1, id[s], x);
		}
		else{
			int a, b;
			cin >> a >> b;
			a--; b--;
			int acc = lca(a, b);
			cout << max(max(path(a, acc, n), path(b, acc, n)), value[acc]) << "\n";
		}
	}	
	return 0;
}
