#include <bits/stdc++.h>

using namespace std;
long long ans = 0;
vector<int> prime;
vector<bool> isprime(1e6 + 1, true);
vector<long long> dp(1e6 + 1, 0);

void sieve(){
	isprime[0] = isprime[1] = false;
	for (long long int i = 2; i < 1e6 + 1; i++){
		if (!isprime[i])
			continue;
		prime.push_back(i);
		for (long long int j = i * i; j < (int)1e6 + 1; j += i)
			isprime[j] = false;
	}
}

int main(){
	sieve();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int input;
		cin >> input;
		vector<int> factor;
		for (int p: prime){
			if (input == 1) break;
			if (isprime[input]){
				factor.push_back(input);
				break;
			}
			if (input % p != 0)
				continue;
			while (input % p == 0)
				input /= p;
			factor.push_back(p);
		}
		for (int bit = 0; bit < (1 << factor.size()); bit++){
			int mulres = 1, count1 = 0;
			for (int j = 0; j < factor.size(); j++)
				if (bit & (1 << j)){
					mulres *= factor[j];
					count1++;
				}
			if (count1 & 1)
				ans -= dp[mulres];
			else
				ans += dp[mulres];
			dp[mulres]++;
		}
	}
	cout << ans << "\n";
	return 0;
}
