#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<int> bit;
int maxn;

void update(int k, int x){
	for (; k <= maxn; k += k & -k)
		bit[k] += x;
}

int query(int r){
	int res = 0;
	for (; r > 0; r -= r & -r)
		res += bit[r];
	return res;
}

int query(int l, int r){
	return query(r) - query(l - 1);
}

struct new_range{
	int id, l, r;
	bool operator <(new_range &b){
		if (l == b.l)
			return r > b.r;
		return l < b.l;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pii> l(n), r(n);
	maxn = n + 5;
	bit.assign(maxn + 1, 0);
	vector<new_range> range(n);
	for (int i = 0; i < n; i++){
		int inputl, inputr;
		cin >> inputl >> inputr;
		l[i] = {inputl, i};
		r[i] = {inputr, i};
		range[i].id = i;
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	int t = 0, last = 0;
	for (int i = 0; i < n; i++){
		if (last != l[i].first) t++;
		range[l[i].second].l = t;
		last = l[i].first;
	}
	t = 0; last = 0;
	for (int i = 0; i < n; i++){
		if (last != r[i].first) t++;
		range[r[i].second].r = t;
		last = r[i].first;
	}

	sort(range.begin(), range.end());

	vector<int> ans(n, 0);
	for (int i = n - 1; i >= 0; i--){
		ans[range[i].id] = query(range[i].r);
		update(range[i].r, 1);
	}
	for (int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";

	// clear bit
	for (int i = 0; i <= maxn; i++)
		bit[i] = 0;

	for (int i = 0; i < n; i++){
		ans[range[i].id] = query(range[i].r, maxn);
		update(range[i].r, 1);
	}
	
	for (int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
