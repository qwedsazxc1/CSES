#include <iostream>

#define MOD ((int)1e9 + 7)

int main(){
    int n;
    scanf("%d", &n);
    long long base = 2, ans = 1;
    while (n){
        if (n & 1){
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
        n >>= 1;
    }
    printf("%lld\n", ans);
    return 0;
}