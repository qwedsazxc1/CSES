#include <bits/stdc++.h>
#define MOD (ll(1e9) + 7)

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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> dp(1 << 20), ans(1 << 20), cnt(1 << 20);
    for (int i = 0; i < n; i++){
        dp[arr[i]]++;
        cnt[arr[i]]++;
    }
    for (int bit = 0; bit < 20; bit++){
        for (int mask = 0; mask < (1 << 20); mask++){
            if (mask & (1 << bit)){
                ans[mask ^ (1 << bit)] += (fast_pow(2, dp[mask] - cnt[mask]) - 1) * (fast_pow(2, dp[mask ^ (1 << bit)]) - 1);
                ans[mask ^ (1 << bit)] %= MOD;
                dp[mask ^ (1 << bit)] += dp[mask];
            }
        }
    }
    for (int mask = 0; mask < (1 << 20); mask++){
        ans[mask] += (fast_pow(2, cnt[mask]) - 1) * fast_pow(2, n - cnt[mask]);
        ans[mask] %= MOD;
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
