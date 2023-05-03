#include <bits/stdc++.h>
#define qr first
#define id second
using namespace std;

struct binary_index_tree{
	vector<int> arr;
	int m;
	binary_index_tree(int n) : arr(n + 1), m(n) {}
	void update(int k, int x){
		for (int i = k; i <= m; i += i & -i)
			arr[i] += x;
	}
	int query(int r){
		int res = 0;
		for (int i = r; i > 0; i -= i & -i)
			res += arr[i];
		return res;
	}
};

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<vector<pair<int, int>>> qry(n);
	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		qry[l].push_back({r, i});
	}
	binary_index_tree bit(n);
	map<int, int> m;
	vector<int> ans(q);
	for (int i = n; i > 0; i--){
		int val = arr[i - 1];
		if (m.count(val) > 0)
			bit.update(m[val], -1);
		m[val] = i;
		bit.update(i, 1);
		for (auto p: qry[i - 1]){
			ans[p.id] = bit.query(p.qr + 1);
		}
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}
