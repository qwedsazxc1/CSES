#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin >> n;
	int cur;
	auto query = [&](int l, int r) -> int {
		cout << l << " " << r << endl;
		int res;
		cin >> res;
		cur = res;
		if (cur == 0){
			exit(0);
		}
		return cur;
	};
	auto cnt = [&](int n) -> int {
		return n * (n - 1) / 2;
	};
	query(1, 1);
	for (int i = 2; i <= n; i++){
		int prev = cur;
		query(1, i);
		int diff = cur - cnt(i - 1) - prev;
		int idx = (diff + i) / 2;
		query(2, i);
		query(1, idx + 1);
		if (idx)
			query(1, idx);
	}
	return 0;
}
