#include <bits/stdc++.h>

using namespace std;

std::mt19937 gen;

struct node{
	node(char val) : val(val), tkey(gen()) {}
	int tkey, size = 1;
	char val;
	node *l = nullptr, *r = nullptr;
};

int size(node *cur){
	return cur ? cur->size : 0;
}

node *merge(node *a, node *b){
	if (!a || !b) return (a ? : b);
	if (a->tkey > b->tkey){
		a->r = merge(a->r, b);
		a->size = size(a->l) + size(a->r) + 1;
		return a;
	}
	else{
		b->l = merge(a, b->l);
		b->size = size(b->l) + size(b->r) + 1;
		return b;
	}
}


void split(node *cur, int k, node *&l, node *&r){
	if (!cur)
		return l = r = nullptr, void();
	if (size(cur->l) <= k){
		l = cur;
		split(cur->r, k - size(cur->l) - 1, l->r, r);
		l->size = size(l->l) + size(l->r) + 1;
	}
	else{
		r = cur;
		split(cur->l, k, l, r->l);
		r->size = size(r->l) + size(r->r) + 1;
	}
}

ostream &operator<<(ostream &os, node *cur){
	if (!cur)
		return os;
	return os << cur->l << cur->val << cur->r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	gen.seed(random_device()());
	int n, q;
	cin >> n >> q;
	node *head = nullptr;
	for (int i = 0; i < n; i++){
		char input;
		cin >> input;
		node *temp = new node(input);
		head = merge(head, temp);
	}	
	
	while (q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		node *a, *temp, *b, *c;
		split(head, l - 1, a, temp);
		split(temp, r - l, b, c);
		temp = merge(a, c);
		temp = merge(temp, b);
		head = temp;
	}
	cout << head;
	cout << "\n";
	return 0;
}
