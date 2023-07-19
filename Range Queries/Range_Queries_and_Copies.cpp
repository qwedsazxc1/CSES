#include <bits/stdc++.h>
using namespace std;
struct node{
	int v;
	long long sum = 0;
	node *l = nullptr, *r = nullptr;
	node(int v){this->v = v;}
	node(){}
};

vector<node *> version;

node *update(node *cur, int l, int r, int k, long long x, int v){
	if (l > k || r < k)
		return ((cur == nullptr) ? new node(v): cur);
	if (l == r){
		cur = new node(v);
		cur->sum = x;
		cur->v = v;
		return cur;
	}
	node *res;
	res = new node(v);
	if (cur == nullptr)
		cur = res;
	int mid = (l + r) / 2;
	res->l = update(cur->l, l, mid, k, x, v);
	res->r = update(cur->r, mid + 1, r, k, x, v);
	res->sum = res->l->sum + res->r->sum;
	return res;
}

long long query(node *cur, int l, int r, int ql, int qr){
	if (r < ql || l > qr)
		return 0;
	if (l >= ql && r <= qr)
		return ((cur == nullptr) ? 0 : cur->sum);
	int mid = (r + l) / 2;
	return query(cur->l, l, mid, ql, qr) + query(cur->r, mid + 1, r, ql, qr);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	version.push_back(nullptr);
	for (int i = 0; i < n; i++)
		version[0] = update(version[0], 0, n - 1, i, arr[i], 0);
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int v, k;
			long long x;
			cin >> v >> k >> x;
			k--; v--;
			version[v] = update(version[v], 0, n - 1, k, x, v);
		}
		else if (op == 2){
			int v, ql, qr;
			cin >> v >> ql >> qr;
			v--; ql--; qr--;
			cout << query(version[v], 0, n - 1, ql, qr) << "\n";
		}
		else{
			int v;
			cin >> v;
			v--;
			version.push_back(version[v]);
		}
	}
	return 0;
}
