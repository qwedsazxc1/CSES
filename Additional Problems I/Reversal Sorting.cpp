#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

struct node{
	int w = rand(), sz = 1, minv, v, tag = 0;
	node *l = nullptr, *r = nullptr;
	node(int v) :minv(v), v(v){}
	void push(){
		if (tag){
			swap(l, r);
			if (l){
				l->tag = !l->tag;
			}
			if (r)
				r->tag = !r->tag;
			tag = 0;
		}
	}
	void pull(){
		sz = 1;
		minv = v;
		if (l){
			sz += l->sz;
			minv = min(minv, l->minv);
		}
		if (r){
			sz += r->sz;
			minv = min(minv, r->minv);
		}
		
	}
};

node *merge(node *l, node *r){
	if (l)
		l->push();
	if (r)
		r->push();
	if (l == nullptr || r == nullptr)
		return l ? : r;
	if (l->w > r->w){
		l->r = merge(l->r, r);
		l->pull();
		return l;
	}
	else{
		r->l = merge(l, r->l);
		r->pull();
		return r;
	}

}



void split(node *cur, node *&l, node *&r, int k){
	if (!cur)
		return l = r = nullptr, void();
	cur->push();
	int lsz = (cur->l ? cur->l->sz : 0);
	if (k >= 1 + lsz){
		l = cur;
		split(cur->r, l->r, r, k - 1 - lsz);
		l->pull();
	}
	else{
		r = cur;
		split(cur->l, l, r->l, k);
		r->pull();
	}
}

int find(node *&cur, int x){
	if (!cur)
		return -1;
	cur->push();
	if (cur->minv > x)
		return -1;
	if (cur->v == x)
		return (cur->l ? cur->l->sz : 0);
	auto res = find(cur->l, x);
	if (res == -1)
		return (cur->l ? cur->l->sz : 0) + 1 + find(cur->r, x);
	return res;
}


void debug(node *root){
	if (!root)
		return;
	debug(root->l);
	cerr << root->v << " ";
	debug(root->r);
}

int main(){
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	node *root = nullptr;
	for (int i = 0; i < n; i++){
		int in;
		cin >> in;
		auto temp = new node(in);
		root = merge(root, temp);
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++){
		int k = find(root, i + 1);
		if (k != i){
			node *templ = nullptr, *tempr = nullptr, *mid = nullptr, *temp = nullptr;
			split(root, templ, temp, i);
			split(temp, mid, tempr, k - i + 1);
			mid->tag = 1;
			root = merge(templ, mid);
			root = merge(root, tempr);
			ans.push_back({i + 1, k + 1});
		}
		k = find(root, i + 1);
		node *templ = nullptr, *tempr = nullptr, *mid = nullptr, *temp = nullptr;
		split(root, templ, temp, k);
		split(temp, mid, tempr, 1);
		mid->v = INF;
		mid->minv = INF;
		root = merge(templ, mid);
		root = merge(root, tempr);
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
}
