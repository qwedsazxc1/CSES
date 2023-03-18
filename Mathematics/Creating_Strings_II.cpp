#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
#define MOD ((long long)1e9 + 7)

long long mod_inverse(long long a, long long mod = MOD){
    long long base = a, ans = 1;
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
    vector<long long> factroial(1e6 + 3);
    factroial[0] = 1;
    for (int i = 1; i < 1e6 + 3; i++){
        factroial[i] = factroial[i - 1] * i % MOD;
    }
    string str;
    cin >> str;
    long long upper = factroial[str.size()];
    map<char, int> count;
    for (auto c: str){
        count[c] += 1;
    }
    long long lower = 1;
    for (auto p: count){
        lower *= factroial[p.second];
        lower %= MOD;
    }
    long long inverse = mod_inverse(lower);
    cout << (upper * inverse) % MOD << "\n";
    return 0;
}