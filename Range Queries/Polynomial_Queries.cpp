#include <bits/stdc++.h>

using namespace std;

struct node{
	long long l, r, s = 0, t = 0, v = 0;
};

vector<node> tree;

void build(int node, long long l, long long r, vector<long long> &arr){
	tree[node].l = l; tree[node].r = r;
	if (l == r){
		tree[node].s = arr[l];
		return;
	}
	long long mid = (l + r) / 2;
	build(node * 2 + 1, l, mid, arr);
	build(node * 2 + 2, mid + 1, r, arr);
	tree[node].s = tree[node * 2 + 1].s + tree[node * 2 + 2].s;
}

long long s(long long n){return (n + 1) * n / 2;}

void push(int k){
	if (long long tag = tree[k].t){
		long long l = tree[k].l, r = tree[k].r;
		tree[k].s += (r - l + 1) * tree[k].v + tree[k].t * s(r - l);
		long long mid = (l + r) / 2;
		if (l != r){
			tree[2 * k + 1].t += tree[k].t;
			tree[2 * k + 1].v += tree[k].v;
			long long lc = mid - l + 1;
			tree[2 * k + 2].t += tree[k].t;
			tree[2 * k + 2].v += tree[k].v + lc * tree[k].t;
		}
		tree[k].t = 0; tree[k].v = 0;
	}
}

void update(int node, long long l, long long r, long long ql, long long qr, long long x = 1){
	push(node);
	if (l > qr || r < ql)
		return;
	if (l >= ql && r <= qr){
		tree[node].v = l - ql + x;
		tree[node].t = 1;
		push(node);
		return;
	}
	long long mid = (l + r) / 2;
	update(node * 2 + 1, l, mid, ql, qr, x);
	update(node * 2 + 2, mid + 1, r, ql, qr, x);
	tree[node].s = tree[node * 2 + 1].s + tree[node * 2 + 2].s;
}

long long query(int node, long long l, long long r, long long ql, long long qr){
	push(node);
	if (l > qr || r < ql)
		return 0;
	if (l >= ql && r <= qr)
		return tree[node].s;
	long long mid = (r + l) / 2;
	return query(node * 2 + 1, l, mid, ql, qr) + query(node * 2 + 2, mid + 1, r, ql, qr); 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> arr(n);
	for (auto &x: arr)
		cin >> x;
	tree.resize(n << 2);
	build(0, 0, n - 1, arr);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			long long ql, qr;
			cin >> ql >> qr;
			ql--; qr--;
			update(0, 0, n - 1, ql, qr);
		}
		else{
			long long ql, qr;
			cin >> ql >> qr;
			ql--; qr--;
			cout << query(0, 0, n - 1, ql, qr) << "\n";
		}
	}	
	return 0;
}
