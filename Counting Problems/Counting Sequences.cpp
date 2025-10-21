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

ll mod_inverse(ll x){
    return fast_pow(x, MOD - 2);
}

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> fact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv[n] = mod_inverse(fact[n]);
    for (ll i = n - 1; i >= 0; i--){
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }
    auto C = [&](ll n, ll k) -> ll {
        return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
    };
    ll ans = 0;
    for (ll i = 0; i <= k; i++){
        ll temp = C(k, i) * fast_pow(k - i, n) % MOD;
        if (i & 1)
            temp = -temp;
        ans = ((ans + temp) % MOD + MOD) % MOD;
    }
    cout << ans << '\n';
}