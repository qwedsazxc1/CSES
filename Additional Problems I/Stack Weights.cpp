#include <bits/stdc++.h>

using namespace std;

struct node{
	int sum = 0;
	int max_suf = 0, min_suf = 0;
};

vector<node> tree;

node pull(node &a, node &b){
	node res;
	res.sum = a.sum + b.sum;
	res.max_suf = max(b.max_suf, b.sum + a.max_suf);
	res.min_suf = min(b.min_suf, b.sum + a.min_suf);
	return res;
}

void update(int cur, int l, int r, int k, int x){
	if (k > r || k < l)
		return;
	if (l == r){
		tree[cur].sum = tree[cur].min_suf = tree[cur].max_suf = x;
		return;
	}
	int mid = (l + r) / 2;
	update(cur * 2 + 1, l, mid, k, x);
	update(cur * 2 + 2, mid + 1, r, k, x);
	tree[cur] = pull(tree[cur * 2 + 1], tree[cur * 2 + 2]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	tree.resize(n << 2);
	for (int i = 0; i < n; i++){
		int c, p;
		cin >> c >> p;
		c--;
		p--;
		if (!p)
			p--;
		update(0, 0, n - 1, c, p);
		node root = tree[0];
		if (root.min_suf >= 0)
			cout << "<\n";
		else if (root.max_suf <= 0)
			cout << ">\n";
		else
			cout << "?\n";
	}
}
