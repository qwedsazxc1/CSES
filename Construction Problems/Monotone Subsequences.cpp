#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		if (k * k < n){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> ans(n);
		iota(ans.begin(), ans.end(), 1);
		int rem = n % k;
		int cnt = n / k;
		int prev = 0;
		for (int i = 0; i < k; i++){
			int next = cnt;
			if (i < rem)
				next++;
			reverse(ans.begin() + prev, ans.begin() + prev + next);
			prev += next;
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i == n - 1];
	}
}
