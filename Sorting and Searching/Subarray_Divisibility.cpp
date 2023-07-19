#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &x: arr)
		cin >> x;
	vector<long long> dp(n, 0);
	dp[0] = 1;
	long long ans = 0, prefix = 0;
	for (int i = 0; i < n; i++){
		prefix += arr[i];
		prefix %= n;
		if (prefix < 0)
			prefix += n;
		ans += dp[prefix];
		dp[prefix] += 1;
	}
	cout << ans << "\n";
	return 0;
}
