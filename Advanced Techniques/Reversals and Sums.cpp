#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
mt19937 mt(random_device{}());

struct node{
	int heapv, size = 1;
	ll sum, val;
	bool tag = false;
	node *l = nullptr, *r = nullptr;
	node(ll v): sum(v), val(v), heapv(mt()){}
	void push(){
		if (!tag)
			return;
		node *temp = l;
		l = r;
		r = temp;
		if (l)
			l->tag = !l->tag;
		if (r)
			r->tag = !r->tag;
		tag = false;
	}
	void pull(){
		sum = val;
		if (l)
			sum += l->sum;
		if (r)
			sum += r->sum;
	}
};

int sz(node *cur){
	return cur ? cur->size : 0;
}

node *merge(node *a, node *b){
	if (a != nullptr)
		a->push();
	if (b != nullptr)
		b->push();
	if (a == nullptr || b == nullptr){
		return a ? : b;
	}
	if (a->heapv > b->heapv){
		a->r = merge(a->r, b);
		a->pull();
		a->size = sz(a->l) + sz(a->r) + 1;
		return a;
	}
	else{
		b->l = merge(a, b->l);
		b->pull();
		b->size = sz(b->l) + sz(b->r) + 1;
		return b;
	}
}

// a will include k
void split(node *cur, node *&a, node *&b, int k){
	if (!cur)
		return a = b = nullptr, void();
	cur->push();
	if (sz(cur->l) <= k){
		a = cur;
		split(cur->r, a->r, b, k - sz(cur->l) - 1);
		a->pull();
		a->size = sz(a->l) + sz(a->r) + 1;
	}
	else{
		b = cur;
		split(cur->l, a, b->l, k);
		b->pull();
		b->size = sz(b->l) + sz(b->r) + 1;
	}
}

ostream& operator<<(ostream &os, node *cur){
	if (!cur)
		return os;
	cur->push(); cur->pull();
	os << cur->l << cur->sum << " " << cur->r;
	return os;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	node *root = nullptr;
	for (int i = 0; i < n; i++){
		ll in;
		cin >> in;
		root = merge(root, new node(in));
	}
	while (q--){
		int op, l, r;
		cin >> op >> l >> r;
		l--; r--;
		node *temp, *a, *b, *c;
		split(root, a, temp, l - 1);
		split(temp, b, c, r - l);
		if (op == 1){
			b->tag = true;
			b->push();
		}
		else{
			cout << b->sum << "\n";
		}
		temp = merge(a, b);
		root = merge(temp, c);
		
	}
	return 0;
}
