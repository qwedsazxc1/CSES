#include <iostream>
#define MOD ((int)(1e9 + 7))
int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == 0){
            printf("1\n");
            continue;
        }

        long long base = a, ans = 1;
        while (b){
            if (b & 1){
                ans *= base;
                ans %= MOD;
            }
            base *= base;
            base %= MOD;
            b >>= 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}