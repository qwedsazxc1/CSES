#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x: arr){
		cin >> x;
		x--;
	}
	vector<int> at(n);
	for (int i = 0; i < n; i++)
		at[arr[i]] = i;
	char c = 'a';
	string ans;
	ans.resize(n);
	ans[arr[0]] = c;
	auto ne = [&](int x) -> int {
		if (arr[x] == n - 1)
			return -1;
		return at[arr[x] + 1];
	};
	int flag = 1;
	for (int i = 1; i < n; i++){
		int prev = ne(i - 1), cur = ne(i);
		if (prev < cur){
			ans[arr[i]] = c;
		}
		else{
			if (c == 'z'){
				cout << "-1\n";
				return 0;
			}
			c++;
			ans[arr[i]] = c;
		}
	}
	cout << ans << "\n";
}
