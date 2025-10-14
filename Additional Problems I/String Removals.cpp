#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
typedef long long ll;

int main(){
	string str;
	cin >> str;
	ll cnt[26] = {};
	ll ans = 1;
	for (auto c: str){
		int cur = c - 'a';
		ll temp = cnt[cur];
		cnt[cur] = ans;
		ans += ans - temp;
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}
	cout << (ans + MOD - 1) % MOD << "\n";
}
