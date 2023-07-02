#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef long long ll;
typedef complex<ll> P;
typedef pair<int, int> pii;

struct line{
	bool horizontal = false;
	P a, b;
	bool operator<(line lb){
		return a.x < lb.a.x;
	}
};
#define MAX_N (ll)2e6 + 5
ll bit[MAX_N] = {};
void update(int k, ll v){
	for (k++; k < MAX_N; k += k & -k)
		bit[k] += v;
}

ll query(int r){
	ll res = 0;
	for (r++; r > 0; r -= r & -r)
		res += bit[r];
	return res;
}

ll query(int l, int r){
	return query(r) - query(l - 1);
}

bool cmp(pair<pii, int> a, pair<pii, int> b){
	
	if (a.first.first == b.first.first)
		return a.second > b.second;
	return a.first.first < b.first.first;
}

istream &operator>>(istream &is, line &in){
	ll x1, y1, x2, y2;
	is >> x1 >> y1 >> x2 >> y2;
	x1 += 1e6;
	x2 += 1e6;
	y1 += 1e6;
	y2 += 1e6;
	if (y1 == y2)
		in.horizontal = true;
	if (x1 > x2)
		swap(x1, x2);
	if (y1 > y2)
		swap(y1, y2);
	in.a = {x1, y1};
	in.b = {x2, y2};
	return is;
}

int main(){
	int n;
	cin >> n;
	line arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<line> hori, vert;
	vector<pair<pii, int>> order;
	hori.reserve(n); vert.reserve(n); order.reserve(2 * n);
	for (int i = 0; i < n; i++)
		if (arr[i].horizontal){
			order.push_back({{arr[i].a.x, arr[i].a.y}, 1});
			order.push_back({{arr[i].b.x, arr[i].a.y}, -1});
		}
		else
			vert.push_back(arr[i]);
	sort(order.begin(), order.end(), cmp);
	sort(vert.begin(), vert.end());
	ll ans = 0;
	int index = 0;
	while (index < vert.size() && vert[index].a.x < order[0].first.first) index++;
	for (int i = 0; i < order.size(); i++){
		while (index < vert.size() && vert[index].a.x < order[i].first.first){
			ans += query(vert[index].a.y, vert[index].b.y);
			index++;
		}
		update(order[i].first.second, order[i].second);
	}
	cout << ans << "\n";

	return 0;
}
