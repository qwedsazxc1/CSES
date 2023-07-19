#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;
typedef pair<int, int> pii;
const int N = 100005;

int tree[N << 2];

void update(int node, int l, int r, int k, int x){
	if (l > k || r < k)
		return;
	if (l == r)
		return tree[node] = x, void();
	int mid = (l + r) / 2;
	update(node * 2 + 1, l, mid, k, x);
	update(node * 2 + 2, mid + 1, r, k, x);
	tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int query(int node, int l, int r, int ql, int qr){
	if (ql > r || qr < l)
		return INF;
	if (l >= ql && r <= qr)
		return tree[node];
	int mid = (l + r) / 2;
	return min(query(node * 2 + 1, l, mid, ql, qr), query(node * 2 + 2, mid + 1, r, ql, qr));
}

void radix_sort(vector<pair<pii, int>> &arr){
	int n = arr.size();
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

int main(){
	int q;
	string str;
	cin >> str >> q;
	vector<int> sa = SA(str);
	memset(tree, INF, sizeof(tree));
	for (int i = 0; i < (int)sa.size(); i++)
		update(0, 0, (int)sa.size() - 1, i, sa[i]);
	while (q--){
		string pat;
		cin >> pat;
		int l = 1, r = (int)sa.size() - 1;
		for (int i = 0; i < (int)pat.size(); i++){
			if (l > r)
				break;
			int newl = r + 1, newr = r + 1, templ = l, tempr = r;
			while (templ <= tempr){
				int mid = (templ + tempr) / 2;
				if (sa[mid] + i < (int)str.size() && str[sa[mid] + i] < pat[i]){
					templ = mid + 1;
				}
				else{
					tempr = mid - 1;
					newl = mid;
				}
			}
			templ = l, tempr = r;
			while (templ <= tempr){
				int mid = (templ + tempr) / 2;
				if (sa[mid] + i < (int)sa.size() && str[sa[mid] + i] <= pat[i])
					templ = mid + 1;
				else {
					newr = mid;
					tempr = mid - 1;
				}
			}
			l = newl, r = newr - 1;
		}
		if (l > r)
			cout << "-1\n";
		else{
			int out = query(0, 0, (int)sa.size() - 1, l, r);
			cout << out + 1 << "\n";
		}
			
	}
	return 0;
}
