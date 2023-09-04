#include <bits/stdc++.h>

using namespace std;

struct union_and_find{
	vector<int> pa_sz;
	union_and_find(int n) :pa_sz(n, -1) {}
	int find(int x){
		if (pa_sz[x] < 0)
			return x;
		return pa_sz[x] = find(pa_sz[x]);
	}
	bool merge(int a, int b){
		a = find(a), b = find(b);
		if (a == b)
			return false;
		if (pa_sz[a] < pa_sz[b])
			swap(a, b);
		pa_sz[b] += pa_sz[a];
		pa_sz[a] = b;
		return true;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	union_and_find dsu(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		dsu.merge(u, v);
	}
	vector<int> allsize;
	for (int i = 0; i < n; i++)
		if (dsu.pa_sz[i] < 0)
			allsize.push_back(-dsu.pa_sz[i]);

	bitset<100001> ans;
	ans[0] = true;
	for (int x: allsize){
		ans |= ans << x;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i];
	cout << "\n";
}
