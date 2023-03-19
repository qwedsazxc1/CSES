#include <iostream>
#include <vector>

#define MOD ((long long)1e9 + 7)

using namespace std;

long long mod_inverse(long long a, long long mod = MOD){
    long long base = a, ans = 1, power = mod - 2;
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
    vector<long long> factorial(2e6 + 5);
    factorial[0] = 1;
    for (long long i = 1; i < factorial.size(); i++){
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    long long n, m;
    cin >> n >> m;
    cout << (factorial[n + m - 1] * mod_inverse(factorial[m]) % MOD) * mod_inverse(factorial[n - 1]) % MOD << "\n";
    return 0;
}