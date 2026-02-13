#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
	string arr = "^#";
	for (int i = 0; i < n; i++){
		arr += str[i];
		arr += "#";
	}
	arr += "$";
	int m = arr.size();
	int r = 0, c = 0;
	vector<int> p(m);
	vector<int> ans(n);
	for (int i = 1; i < m; i++){
		if (i < r){
			p[i] = min(p[2 * c - i], r - i);
		}
		if (i + p[i] >= r){
			while (r + 1 < m && 2 * i - r - 1 >= 0 && arr[r + 1] == arr[2 * i - r - 1]){
				c = i;
				r++;
				p[i]++;
				if (r > 0 && r != m - 1 && ((r - 1) & 1)){
					ans[(r - 1) / 2] = (r - c) + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];

}
