#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main(){
	int n, k;
	cin >> n >> k;
	map<pii, int> m;
	auto query = [&](int group, int ord) -> int {
		if (m.find({group, ord}) != m.end())
			return m[{group, ord}];
		cout << "FS"[group] << " " << ord << endl;
		int res;
		cin >> res;
		m[{group, ord}] = res;
		return res;
	};
	if (query(0, n) > query(1, 1) || query(1, n) > query(0, 1)){
		int type = 0;
		if (query(1, n) > query(0, 1))
			type = 1;
		if (k > n){
			k -= n;
			type ^= 1;
		}
		cout << "! " << query(type, k) << endl;
		return 0;
	}
	int r = min(n, k), l = max(1, k - n);
	int res = r;
	while (l < r){
		int mid = (l + r) / 2;
		int temp = k - mid;
		if (query(0, mid) > query(1, temp)){
			r = mid;
		}
		else{
			res = mid;
			l = mid + 1;
		}
	}
	int ans = query(0, res);
	if (query(0, res) > query(1, k - res + 1))
		ans = query(1, k - res + 1);
	cout << "! " << ans << endl;

}
