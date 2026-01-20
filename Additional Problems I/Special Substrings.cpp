#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	string str;
	cin >> str;
	ll n = str.size();
	map<char, ll> m;
	map<vector<ll>, ll> mcnt;
	for (int i = 0; i < n; i++){
		if (m.find(str[i]) == m.end()){
			int sz = m.size();
			m[str[i]] = sz;
		}
	}
	if (m.size() == 1){
		cout << n * (n + 1) / 2 << "\n";
		return 0;
	}
	vector<ll> cnt(m.size());
	vector<ll> temp(m.size() - 1);
	mcnt[temp]++;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		cnt[m[str[i]]]++;
		vector<ll> temp(m.size() - 1);
		for (int j = 0; j < temp.size(); j++){
			temp[j] = cnt[0] - cnt[j + 1];
		}
		ans += mcnt[temp];
		mcnt[temp]++;
	}
	cout << ans << "\n";
}
