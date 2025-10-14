#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;

int nxt[maxn][20];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> arr(n);
	for (auto &p: arr)
		cin >> p.second >> p.first;
	sort(arr.begin(), arr.end());
	int index = 0;
	for (int i = 0; i < maxn; i++){
		while (index < n && arr[index].second < i)
			index++;
		if (index == n){
			nxt[i][0] = maxn - 1;
		}
		else{
			nxt[i][0] = arr[index].first;
		}
	}
	for (int i = 1; i < 20; i++)
		for (int j = 0; j < maxn; j++){
			nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
		}
	while (q--){
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for (int i = 19; i >= 0; i--){
			if (nxt[l][i] <= r){
				l = nxt[l][i];
				ans += 1 << i;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
