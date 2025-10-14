#include <bits/stdc++.h>

using namespace std;

struct union_and_find{
	int compoment;
	vector<int> pa_sz;
	union_and_find(int n) : pa_sz(n, -1), compoment(n) {}
	int find(int a){
		if (pa_sz[a] < 0) return a;
		return pa_sz[a] = find(pa_sz[a]);
	}
	bool _union(int a, int b){
		a = find(a), b = find(b);
		if (a == b)
			return false;
		compoment--;
		if (pa_sz[a] < pa_sz[b])
			swap(a, b);
		pa_sz[b] += pa_sz[a];
		pa_sz[a] = b;
		return true;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<pair<int, int>> s;
	int n, m, q;
	cin >> n >> m >> q;
	union_and_find dsu(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u > v)
			swap(u, v);
		s.insert({u, v});
	}
	stack<pair<int, int>> stk;
	for (int i = 0; i < q; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u > v)
			swap(u, v);
		stk.push({u, v});
		s.erase({u, v});
	}
	for (auto p: s)
		dsu._union(p.first, p.second);
	
	stack<int> res;
	for (int i = 0; i < q; i++){
		auto t = stk.top();
		stk.pop();
		res.push(dsu.compoment);
		dsu._union(t.first, t.second);
	}
	while (!res.empty()){
		cout << res.top() << " ";
		res.pop();
	}
	cout << "\n";
	return 0;
}
