#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
	map<char, int> cnt;
	for (auto c: str)
		cnt[c]++;
	map<char, int> pos;
	pos['#'] = 0;
	pos['a'] = 1;
	for (char c = 'b'; c <= 'z'; c++)
		pos[c] = pos[c - 1] + cnt[c - 1];
	int cur = 0;
	string ans = "";
	vector<int> next(n);
	for (int i = 0; i < n; i++){
		next[i] = pos[str[i]]++;
	}
	for (int i = 0; i < n - 1; i++){
		ans += str[cur];
		cur = next[cur];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}
