#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (n == 2){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 1);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int flag = 1;
	while (flag){
		shuffle(ans.begin(), ans.end(), rng);
		flag = 0;
		for (int i = 0; i < n; i++){
			if (a[i] == ans[i] || b[i] == ans[i]){
				flag = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
}
