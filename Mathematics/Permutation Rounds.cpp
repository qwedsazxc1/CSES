#include <bits/stdc++.h>
#define MOD ((long long)1e9 + 7)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

map<ll, ll> factor(ll n) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n > 1) 
        res[n]++;
    return res;
}

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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    map<ll, ll> m;
    vector<int> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) 
            continue;
        int cur = i, cnt = 0;
        while (!visited[cur]) {
            visited[cur] = 1;
            cur = p[cur];
            cnt++;
        }
        for (auto [x, y] : factor(cnt)) {
            m[x] = max(m[x], y);
        }
    }
    ll ans = 1;
    for (auto [x, y] : m) {
        ans *= fast_pow(x, y);
        ans %= MOD;
    }
    cout << ans << "\n";
}