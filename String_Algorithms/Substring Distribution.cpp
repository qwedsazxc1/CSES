#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int N = 100005;

struct node{
	int tag, sum, l, r;
};

node tree[N << 2];

void push(int index){
	if (!tree[index].tag)
		return;
	int tag_value = tree[index].tag;
	tree[index].sum += (tree[index].r - tree[index].l + 1) * tag_value;
	tree[index].tag = 0;
	if (tree[index].l == tree[index].r)
		return;
	tree[index * 2 + 1].tag += tag_value;
	tree[index * 2 + 2].tag += tag_value;
}

void update(int node_index, int l, int r, int ql, int qr, int x){
	tree[node_index].l = l, tree[node_index].r = r;
	push(node_index);
	if (l > qr || r < ql)
		return;
	if (l >= ql && r <= qr){
		tree[node_index].tag = x;
		push(node_index);
		return;
	}
	int mid = (l + r) >> 1;
	update(node_index * 2 + 1, l, mid, ql, qr, x);
	update(node_index * 2 + 2, mid + 1, r, ql, qr, x);
	tree[node_index].sum = tree[node_index * 2 + 1].sum + tree[node_index * 2 + 2].sum;
}

int query(int index, int l, int r, int ql, int qr){
	push(index);
	if (l > qr || r < ql)
		return 0;
	if (l >= ql && r <= qr)
		return tree[index].sum;
	int mid = (l + r) >> 1;
	return query(index * 2 + 1, l, mid, ql, qr) + query(index * 2 + 2, mid + 1, r, ql, qr);
}

void radix_sort(vector<pair<pii, int>> &arr){
	int n = (int)arr.size();
	vector<int> cnt(n, 0), pos(n);
	// sort second
	{
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.second]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.second]++] = arr[i];
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
	// sort first
	{
		cnt.assign(n, 0);
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.first]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.first]++] = arr[i];
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
}

vector<int> SA(string &str){
	str += "*";
	int n = (int)str.size();
	vector<int> res(n);
	// preprocess
	{
		vector<pair<char, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[i] = {str[i], i};
		sort(temp.begin(), temp.end());
		int cnt = 0;
		res[temp[0].second] = 0;
		for (int i = 1; i < n; i++)
			if (temp[i].first == temp[i - 1].first)
				res[temp[i].second] = cnt;
			else
				res[temp[i].second] = ++cnt;
	}

	for (int k = 0; (1 << k) <= n; k++){
		vector<pair<pii, int>> label(n);
		for (int i = 0; i < n; i++)
			label[i] = {{res[i], res[(i + (1 << k)) % n]}, i};
		radix_sort(label);
		int cnt = 0;
		res[label[0].second] = 0;
		for (int i = 1; i < n; i++)
			if (label[i].first == label[i - 1].first)
				res[label[i].second] = cnt;
			else
				res[label[i].second] = ++cnt;
	}
	vector<int> sa(n);
	for (int i = 0; i < n; i++)
		sa[res[i]] = i;
	return sa;
}

vector<int> LCP(vector<int> &sa, string &str){
	int n = (int)sa.size();
	vector<int> order(n), lcp(n, 0);
	for (int i = 0; i < n; i++)
		order[sa[i]] = i;
	int pre = 0;
	for (int i = 0; i < n - 1; i++){
		if (order[i] == n - 1)
			continue;
		if (pre > 0) pre--;
		int j = sa[order[i] + 1];
		while (i + pre < n && j + pre < n && str[i + pre] == str[j + pre])
			pre++;
		lcp[order[i]] = pre;
	}
	return lcp;
}

int main(){
	string str;
	cin >> str;
	vector<int> sa = SA(str);
	vector<int> lcp = LCP(sa, str);
	int n = (int)sa.size();
	vector<int> ans(n, 0);
	for (int i = 1; i < n; i++){
		int l = lcp[i] + 1;
		int r = n - 1 - sa[i];
		update(0, 0, n - 1, l, r, 1);
	}
	for (int i = 1; i < n; i++)
		cout << query(0, 0, n - 1, i, i) << " ";
	cout << "\n";
	return 0;
}
