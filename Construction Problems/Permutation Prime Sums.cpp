#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll maxn = 1e6;
    vector<int> is_prime(maxn + 1, 1);
    auto sieve = [&](){
        is_prime[0] = is_prime[1] = 0;
        for(ll i = 2; i * i <= maxn; i++){
            if(is_prime[i]){
                for(ll j = i * i; j <= maxn; j += i){
                    is_prime[j] = 0;
                }
            }
        }
    };
    vector<int> primes;
    sieve();
    for(int i = 2; i <= maxn; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    int n;
    cin >> n;
    vector<int> ans(n);
    if(n == 1){
        cout << "1\n1\n";
        return 0;
    }
    int cur = n;
    while (cur > 0){
        int p = *upper_bound(primes.begin(), primes.end(), cur);
        for (int i = cur; i >= p - cur; i--){
            ans[i - 1] = p - i;
        }
        cur = p - cur - 1;
    }

    for (int i = 0; i < n; i++){
        cout << i + 1 << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}