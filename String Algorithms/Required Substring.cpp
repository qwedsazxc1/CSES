#include <bits/stdc++.h>
#define MOD ((ll)1e9 + 7)

using namespace std;
using ll = long long;

ll fast_pow(ll base, ll power){
	ll res = 1;
	while (power){
		if (power & 1){
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		power >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int m = str.size();
	auto _pi = [&]() -> vector<int> {
		vector<int> res(m);
		int j = 0;
		for (int i = 1; i < m; i++){
			while (j > 0 && str[i] != str[j]){
				j = res[j - 1];
			}
			if (str[i] == str[j])
				j++;
			res[i] = j;
		}
		return res;
	};
	vector<int> pi = _pi();
	vector<vector<int>> tran(m, vector<int>(26));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < 26; j++){
			int temp = i;
			while (temp > 0 && str[temp] != 'A' + j){
				temp = pi[temp - 1];
			}
			if (str[temp] == 'A' + j)
				temp++;
			tran[i][j] = temp;
		}
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(m));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < 26; k++){
				if (tran[j][k] < m)
					dp[i + 1][tran[j][k]] += dp[i][j];
			}
		}
		for (int j = 0; j < m; j++){
			dp[i + 1][j] %= MOD;
		}
	}
	ll sum = 0;
	ll ans = fast_pow(26, n);
	for (int i = 0; i < m; i++){
		sum += dp[n][i];
	}
	sum %= MOD;
	ans -= sum;
	ans += MOD;
	ans %= MOD;
	cout << ans << "\n";
}
