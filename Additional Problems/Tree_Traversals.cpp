#include <bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node *l = nullptr, *r = nullptr;
	node(int v): val(v){}
};

ostream &operator<<(ostream &os, node *cur){
	if (cur == nullptr)
		return os;
	os << cur->l;
	os << cur->r;
	os << cur->val << " ";
	return os;
}

int main(){
	int n;
	cin >> n;
	vector<int> preorder(n), inorder(n);
	for (auto &x: preorder)
		cin >> x;
	for (auto &x: inorder)
		cin >> x;
	stack<node *> s; 
	node *cur = nullptr, *head;
	int index = 0;
	for (int i = 0; i < n; i++){
		if (!s.empty() && s.top()->val == inorder[i]){
			cur = s.top();
			s.pop();
			continue;
		}
		node *t = new node(preorder[index++]);
		s.push(t);
		if (cur == nullptr)
			cur = t, head = t;
		else
			cur->r = t;
		while (s.top()->val != inorder[i]){
			node *temp = new node(preorder[index++]);
			s.top()->l = temp;
			s.push(temp);
		}
		cur = s.top();
		s.pop();
	}
	cout << head;
	cout << "\n";
	return 0;
}
