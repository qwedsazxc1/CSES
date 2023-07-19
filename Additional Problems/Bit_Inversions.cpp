#include <bits/stdc++.h>

using namespace std;

struct node{
	int maxl = 1, lbit = 0, rbit = 0, ll = 1, rl = 1;

};

vector<node> tree;

void build(int cur, int l, int r, string &str){
	if (l == r){
		tree[cur].ll = tree[cur].rl = tree[cur].maxl = 1;
		tree[cur].lbit = tree[cur].rbit = str[l] - '0';
		return;
	}
	int mid = (l + r) / 2;
	build(cur * 2 + 1, l, mid, str);
	build(cur * 2 + 2, mid + 1, r, str);
	node temp;
	node ln = tree[cur * 2 + 1], rn = tree[cur * 2 + 2];
	temp.rbit = rn.rbit;
	temp.lbit = ln.lbit;
	temp.ll = ln.ll;
	if (ln.ll == (mid - l + 1) && ln.lbit == rn.lbit)
		temp.ll += rn.ll;
	temp.rl = rn.rl;
	if (rn.rl == (r - mid) && ln.rbit == rn.rbit)
		temp.rl += ln.rl;
	if (ln.rbit == rn.lbit)
		temp.maxl = ln.rl + rn.ll;
	temp.maxl = max(temp.maxl, max(ln.maxl, rn.maxl));

	tree[cur] = temp;
}

void update(int cur, int l, int r, int k, int x){
	if (k < l || k > r)
		return;
	if (l == r){
		tree[cur].ll = tree[cur].rl = tree[cur].maxl = 1;
		tree[cur].lbit = tree[cur].rbit = x;
		return;
	}
	int mid = (l + r) / 2;
	update(cur * 2 + 1, l, mid, k, x);
	update(cur * 2 + 2, mid + 1, r, k, x);
	node temp;
	node ln = tree[cur * 2 + 1], rn = tree[cur * 2 + 2];
	temp.rbit = rn.rbit;
	temp.lbit = ln.lbit;
	temp.ll = ln.ll;
	if (ln.ll == (mid - l + 1) && ln.lbit == rn.lbit)
		temp.ll += rn.ll;
	temp.rl = rn.rl;
	if (rn.rl == (r - mid) && ln.rbit == rn.rbit)
		temp.rl += ln.rl;
	if (ln.rbit == rn.lbit)
		temp.maxl = ln.rl + rn.ll;
	temp.maxl = max(temp.maxl, max(ln.maxl, rn.maxl));

	tree[cur] = temp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
	tree.resize(n << 2);
	build(0, 0, n - 1, str);
	int q;
	cin >> q;
	while (q--){
		int k;
		cin >> k;
		k--;
		if (str[k] == '0')
			str[k] = '1';
		else
			str[k] = '0';
		update(0, 0, n - 1, k, str[k] - '0');
		cout << tree[0].maxl << " ";
	}
	cout << "\n";
	return 0;
}
