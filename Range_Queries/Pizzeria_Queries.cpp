#include <bits/stdc++.h>
#define INF (long long)0x3f3f3f3f3f3f3f3f
using namespace std;

struct node{
	long long l_min = 0, r_min = 0, range = 0;
};

vector<node> tree;

void update(int node, int l, int r, int k, long long int x){
	if (k > r || k < l){
		return;
	}
	if (l == r){
		tree[node].l_min = x;
		tree[node].r_min = x;
		tree[node].range = 1;
		return;
	}
	int mid = (r + l) / 2;
	update(node * 2 + 1, l, mid, k, x);
	update(node * 2 + 2, mid + 1, r, k, x);
	tree[node].range = tree[node * 2 + 2].range + tree[node * 2 + 1].range;
	tree[node].l_min = min(tree[node * 2 + 1].l_min, tree[node * 2 + 2].l_min + tree[node * 2 + 1].range);
	tree[node].r_min = min(tree[node * 2 + 2].r_min, tree[node * 2 + 1].r_min + tree[node * 2 + 2].range);
}

node query(int node, int l, int r, int ql, int qr){
	if (l > qr || r < ql)
		return (struct node){INF, INF, 0};
	if (l >= ql && r <= qr){
		return tree[node];
	}
	int mid = (l + r) / 2;
	struct node res_l = query(node * 2 + 1, l, mid, ql, qr), res_r = query(node * 2 + 2, mid + 1, r, ql, qr), res;
	res.range = res_l.range + res_r.range;
	res.l_min = min(res_l.l_min, res_r.l_min + res_l.range);
	res.r_min = min(res_r.r_min, res_l.r_min + res_r.range);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	tree.resize(n << 2);
	vector<long long> arr(n);
	for (int i = 0; i < n; i++){
		long long input;
		cin >> input;
		arr[i] = input;
		update(0, 0, n - 1, i, input);
	}
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int k;
			long long x;
			cin >> k >> x;
			k--;
			arr[k] = x;
			update(0, 0, n - 1, k, x);
		}
		else{
			int k;
			cin >> k;
			k--;
			node l = query(0, 0, n - 1, 0, k - 1), r = query(0, 0, n - 1, k + 1, n - 1);
			cout << min(arr[k], min(l.r_min, r.l_min) + 1) << "\n";
		}
	}
	return 0;
}
