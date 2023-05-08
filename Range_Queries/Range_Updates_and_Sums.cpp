#include <bits/stdc++.h>

using namespace std;

struct node{
	long long s = 0, v = 0;
	// 1 means add, 2 means set
	int t = 0, l, r;
};

vector<node> tree;

void push(int k){
	if (tree[k].t){
		if (tree[k].t == 1){
			if (tree[k].l == tree[k].r){
				tree[k].s += tree[k].v;
				tree[k].t = tree[k].v = 0;
				return;
			}
			tree[k].s += (tree[k].r - tree[k].l + 1) * tree[k].v;
			if (!tree[2 * k + 1].t)
				tree[2 * k + 1].t = 1;
			if (!tree[2 * k + 2].t)
				tree[2 * k + 2].t = 1;
			tree[2 * k + 1].v += tree[k].v;
			tree[2 * k + 2].v += tree[k].v;
			tree[k].t = tree[k].v = 0;
		}
		else{
			if (tree[k].l == tree[k].r){
				tree[k].s = tree[k].v;
				tree[k].t = tree[k].v = 0;
				return;
			}
			tree[k].s = (tree[k].r - tree[k].l + 1) * tree[k].v;
			tree[k * 2 + 2].t = tree[k * 2 + 1].t = 2;
			tree[k * 2 + 2].v = tree[k * 2 + 1].v = tree[k].v;
			tree[k].t = tree[k].v = 0;
		}
	}
}

void build(int node, int l, int r, vector<long long> &arr){
	tree[node].l = l; tree[node].r = r;
	if (l == r){
		tree[node].s = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(node * 2 + 1, l, mid, arr);
	build(node * 2 + 2, mid + 1, r, arr);
	tree[node].s = tree[node * 2 + 1].s + tree[node * 2 + 2].s;
}

void update_add(int node, int l, int r, int ql, int qr, long long x){
	push(node);
	if (ql > r || qr < l){
		return;
	}
	if (l >= ql && r <= qr){
		tree[node].t = 1;
		tree[node].v = x;
		return;
	}
	tree[node].s += x * (min(qr, r) - max(ql, l) + 1);
	int mid = (r + l) / 2;
	update_add(node * 2 + 1, l, mid, ql, qr, x);
	update_add(node * 2 + 2, mid + 1, r, ql, qr, x);
}

void update_set(int node, int l, int r, int ql, int qr, long long x){
	push(node);
	if (ql > r || qr < l)
		return;
	if (l >= ql && r <= qr){
		tree[node].v = x;
		tree[node].t = 2;
		push(node);
		return;
	}
	int mid = (l + r) / 2;
	update_set(node * 2 + 1, l, mid, ql, qr, x);
	update_set(node * 2 + 2, mid + 1, r, ql, qr, x);
	tree[node].s = tree[node * 2 + 1].s + tree[node * 2 + 2].s;
}

long long query(int node, int l, int r, int ql, int qr){
	push(node);
	if (qr < l || ql > r)
		return 0;
	if (l >= ql && r <= qr)
		return tree[node].s;
	int mid = (l + r) / 2;
	return query(node * 2 + 1, l, mid, ql, qr) + \
	query(node * 2 + 2, mid + 1, r, ql, qr);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	tree.resize(n << 2);
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(0, 0, n - 1, arr);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int ql, qr;
			long long x;
			cin >> ql >> qr >> x;
			ql--; qr--;
			update_add(0, 0, n - 1, ql, qr, x);
		}
		else if (op == 2){
			int ql, qr;
			long long x;
			cin >> ql >> qr >> x;
			ql--; qr--;
			update_set(0, 0, n - 1, ql, qr, x);
		}
		else{
			int ql, qr;
			cin >> ql >> qr;
			ql--; qr--;
			cout << query(0, 0, n - 1, ql, qr) << "\n";
		}
	}
	return 0;
}
