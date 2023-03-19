#include <iostream>
#include <algorithm>
#include <map>
#define MOD ((long long)1e9 + 7)

using namespace std;

long long mod_inverse(long long a, long long mod = MOD){
    long long ans = 1, base = a;
    long long power = mod - 2;
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
    long long mod_inverse_of_2 = mod_inverse(2LL);
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1, j; i <= n; i = j){
        long long q = n / i;
        j = n / q + 1;
        long long upper_bound = (j - 1) % MOD, lower_bound = (i - 1) % MOD;

        long long sum = ((upper_bound + 1) * upper_bound % MOD * mod_inverse_of_2 % MOD) - \
        (((lower_bound + 1) * lower_bound % MOD * mod_inverse_of_2 % MOD));
        if (sum < 0)
            sum += MOD;
        ans += (sum * q) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}