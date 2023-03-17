// Your task is to efficiently calculate values abc
// modulo 10^9+7

// Note that in this task we assume that 0^0=1
// Input

// The first input line has an integer n : the number of calculations.
// After this, there are n lines, each containing three integers a, b and c

// Output

// Print each value a^(b^c)
//  modulo 10^9+7

// Constraints
// 1 <= n <= 10^5

// 0 <= a,b,c <= 10^9

// Example

// Input 1:
// 3
// 3 7 1
// 15 2 2
// 3 4 5

// Output 1:
// 2187
// 50625
// 763327764

// Input 2:
// 1
// 140306 140306 140306

// Correct output 2:
// 191305161

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD ((long long)1000000007)
ll power(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1)
        {
            res=(res*a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while (t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = power(a,power(b,c, MOD - 1), MOD);
        cout << ans << endl;
    }
    return 0;
}
