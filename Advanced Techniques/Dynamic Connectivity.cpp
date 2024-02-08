#include <bits/stdc++.h>

using namespace std;

struct union_and_find{
	vector<int> pa_sz, chi, par, sz, res;
	int cnt;
	void init(int n){
		pa_sz.assign(n, -1);
		cnt = n;
	}
	void roll(){
		if (!res.back()){
			res.pop_back();
			return;
		}
		pa_sz[par.back()] -= sz.back();
		pa_sz[chi.back()] = sz.back();
		par.pop_back();
		sz.pop_back();
		chi.pop_back();
		res.pop_back();
		cnt++;
	}
	int find(int a){
		if (pa_sz[a] < 0)
			return a;
		return find(pa_sz[a]);
	}
	bool merge(int a, int b){
		a = find(a), b = find(b);
		if (a == b){
			res.push_back(0);
			return false;
		}
		if (pa_sz[a] < pa_sz[b])
			swap(a, b);
		chi.push_back(a);
		sz.push_back(pa_sz[a]);
		par.push_back(b);
		res.push_back(1);
		pa_sz[b] += pa_sz[a];
		pa_sz[a] = b;
		cnt--;
		return true;
	}
};

struct edge{
	int u, v, s, e;
};

union_and_find dsu;
map<pair<int, int>, vector<edge>> addlist;
vector<int> ans;

void add_range(int l, int r, edge &e){
	if (r < e.s || l > e.e)
		return;
	if (l >= e.s && r <= e.e){
		addlist[{l, r}].push_back(e);
		return;
	}
	int mid = (l + r) / 2;
	add_range(l, mid, e);
	add_range(mid + 1, r, e);
}

void solve(int l, int r){
	for (auto &e: addlist[{l, r}]){
		dsu.merge(e.u, e.v);
	}
	if (l == r){
		ans[l] = dsu.cnt;
		for (auto &e: addlist[{l, r}])
			dsu.roll();
		return;
	}
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid + 1, r);
	for (auto &e: addlist[{l, r}])
		dsu.roll();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	dsu.init(n);
	vector<edge> elist;
	elist.reserve(m + q);
	ans.resize(q + 1);
	map<pair<int, int>, pair<int, int>> range;

	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u > v)
			swap(u, v);
		range[{u, v}] = {0, q};
	}

	for (int i = 1; i <= q; i++){
		int op, u, v;
		cin >> op >> u >> v;
		u--; v--;
		if (u > v)
			swap(u, v);
		if (op == 1)
			range[{u, v}] = {i, q};
		else{
			auto it = range.find({u, v});
			elist.push_back({u, v, it->second.first, i - 1});
			range.erase(it);
		}
	}
	for (auto p: range)
		elist.push_back({p.first.first, p.first.second, p.second.first, p.second.second});
	for (auto e: elist)
		add_range(0, q, e);
	
	solve(0, q);

	for (int i = 0; i <= q; i++)
		cout << ans[i] << " \n"[i == q];
}
