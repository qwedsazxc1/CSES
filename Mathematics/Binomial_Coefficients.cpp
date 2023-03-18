#include <iostream>
#include <vector>
#include <algorithm>

#define MOD ((long long)1e9 + 7)

using namespace std;

long long mod_inverse(long long a, long long mod = MOD){
    long long power = mod - 2;
    long long ans = 1, base = a;
    while (power){
        if (power & 1){
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        power >>= 1;
    }
    return ans;
}

int main(){
    vector<long long> factorial(1e6 + 3);
    factorial[0] = 1;
    for (int i = 1; i < 1e6 + 3; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        long long lower = (factorial[b] * factorial[a - b]) % MOD;
        long long upper = factorial[a];
        long long inverse = mod_inverse(lower);
        cout << upper * inverse % MOD << "\n";
    }
    return 0;
}