#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void update(int node, int l, int r, int k, int x){
	if (l > k || r < k)
		return;
	if (l == r){
		tree[node] += x;
		return;
	}
	int mid = (l + r) / 2;
	update(node * 2 + 1, l, mid, k, x);
	update(node * 2 + 2, mid + 1, r, k, x);
	tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

int query(int node, int l, int r, int k){
	if (l == r)
		return l;
	int mid = (l + r) / 2;
	if (tree[node * 2 + 1] > k)
		return query(node * 2 + 1, l, mid, k);
	else
		return query(node * 2 + 2, mid + 1, r, k - tree[node * 2 + 1]);
}

int main(){
	int n, k;
	cin >> n >> k;
	tree.resize(n << 2);
	for (int i = 0; i < n; i++)
		update(0, 0, n - 1, i, 1);
	int cursize = n, at = 0;
	for (int i = 0; i < n; i++){
		at += k;
		at %= cursize;
		int res = query(0, 0, n - 1, at);
		cout << res + 1 << " ";
		update(0, 0, n - 1, res, -1);
		cursize--;
	}
	cout << "\n";
	return 0;
}
