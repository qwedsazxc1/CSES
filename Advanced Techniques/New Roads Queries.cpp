#include <bits/stdc++.h>

using namespace std;

struct union_and_find{
	int n;
	vector<int> pa_sz;
	void init(){
		pa_sz.assign(n, -1);	
	}
	union_and_find(int n) : n(n) {
		init();
	}
	int find(int a){
		if (pa_sz[a] < 0)
			return a;
		return pa_sz[a] = find(pa_sz[a]);
	}
	bool merge(int a, int b){
		a = find(a), b = find(b);
		if (a == b)
			return false;
		if (pa_sz[b] < pa_sz[a])
			swap(a, b);
		pa_sz[a] += pa_sz[b];
		pa_sz[b] = a;
		return true;
	}
};

struct query{
	int l, r, u, v;
};

int main(){
	int n, m, q;
	cin >> n >> m >> q;
	union_and_find dsu(n);
	vector<pair<int, int>> edge(m);
	for (auto &p: edge){
		cin >> p.first >> p.second;
		p.first--; p.second--;
	}
	vector<query> queries(q);
	vector<int> time[m + 1];
	for (int i = 0; i < q; i++){
		cin >> queries[i].u >> queries[i].v;
		queries[i].u--; queries[i].v--;
		queries[i].l = 0;
		queries[i].r = m + 1;
		time[(n + 1) / 2].push_back(i);
	}

	bool flag = true;
	while (flag){
		flag = false;
		dsu.init();
		for (int i = 0; i <= m; i++){
			if (i != 0)
				dsu.merge(edge[i - 1].first, edge[i - 1].second);
			while (time[i].size() > 0){
				int id = time[i].back(), l, r;
				time[i].pop_back();
				if (dsu.find(queries[id].u) == dsu.find(queries[id].v)){
					l = queries[id].l, r = i;
					queries[id].r = r;
				}
				else{
					l = i + 1, r = queries[id].r;
					queries[id].l = l;
				}
				if (l != r){
					flag = true;
					time[(l + r) / 2].push_back(id);
				}
			}
		}
	}
	for (int i = 0; i < q; i++){
		if (queries[i].l == m + 1)
			queries[i].l = -1;
		cout << queries[i].l << "\n";
	}
	return 0;
}
