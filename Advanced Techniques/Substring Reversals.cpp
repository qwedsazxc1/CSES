#include <bits/stdc++.h>

using namespace std;

mt19937 mt(random_device{}());

struct node{
	int heapv, size = 1;
	node *l = nullptr, *r = nullptr;
	bool tag = false;
	char v;
	node(char c): v(c), heapv(mt()){}
	void push(){
		if (!tag)
			return;
		node *temp = l;
		l = r;
		r = temp;
		tag = false;
		if (l != nullptr)
			l->tag = !l->tag;
		if (r != nullptr)
			r->tag = !r->tag;
	}
};

int sz(node *cur){
	return cur ? cur->size : 0;
}

node *merge(node *a, node *b){
	if (a == nullptr || b == nullptr){
		if (a == nullptr && b == nullptr)
			return nullptr;
		if (a == nullptr){
			b->push();
			return b;
		}
		a->push();
		return a;
	}
	a->push(); b->push();
	if (b->heapv > a->heapv){
		b->l = merge(a, b->l);
		b->size = sz(b->l) + sz(b->r) + 1;
		return b;
	}
	else{
		a->r = merge(a->r, b);
		a->size = sz(a->l) + sz(a->r) + 1;
		return a;
	}
}

// a will include k
void split(node *cur, node *&a, node *&b, int k){
	if (cur == nullptr)
		return a = b = nullptr, void();
	cur->push();
	if (sz(cur->l) <= k){
		a = cur;
		split(cur->r, a->r, b, k - sz(cur->l) - 1);
		a->size = sz(a->l) + sz(a->r) + 1;
	}
	else{
		b = cur;
		split(cur->l, a, b->l, k);
		b->size = sz(b->l) + sz(b->r) + 1;
	}
}

ostream& operator<<(ostream &os, node *cur){
	if (cur == nullptr)
		return os;
	cur->push();
	os << cur->l;
	os << cur->v;
	os << cur->r;
	return os;
}

int main(){
	int n, q;
	cin >> n >> q;
	string str;
	cin >> str;
	node *root = new node(str[0]);
	for (int i = 1; i < n; i++){
		node *temp = new node(str[i]);
		root = merge(root, temp);
	}
	while (q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		node *temp = nullptr, *a = nullptr, *b = nullptr, *c = nullptr;
		split(root, a, temp, l - 1);
		split(temp, b, c, r - l);
		b->tag = true;
		temp = merge(a, b);
		root = merge(temp, c);
	}
	cout << root << "\n";
	return 0;
}
