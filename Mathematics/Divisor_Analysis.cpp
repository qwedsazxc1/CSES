#include <iostream>
#include <vector>
#define MOD ((long long)1e9 + 7)
using namespace std;

long long fast_pow(long long base, long long power, long long mod = MOD){
    long long ans = 1;
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

long long mod_inverse(long long a, long long mod = MOD){
    return fast_pow(a, mod - 2);
}

int main(){
    int n;
    cin >> n;
    long long first = 1, second = 1, third = 1, temp, cnt = 1;
    while (n--){
        long long base, exp;
        cin >> base >> exp;
        first *= (exp + 1LL);
        first %= MOD;
        temp = fast_pow(base, exp + 1) - 1;
        if (temp < 0)
            temp += MOD;
        second *= (temp * mod_inverse(base - 1) % MOD);
        second %= MOD;
        third = fast_pow(third, exp + 1);
        third *= fast_pow(base, ((exp + 1) * exp / 2) % (MOD - 1) * cnt % (MOD - 1));
        third %= MOD;
        cnt *= exp + 1;
        cnt %= MOD - 1;
    }
    cout << first << " " << second << " " << third << "\n";
    return 0;
}