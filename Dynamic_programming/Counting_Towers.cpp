#include <iostream>
#define MOD ((int)1e9 + 7)

int main(){
    int t;
    scanf("%d", &t);
    int n = 1000000;
    long long **cobin = (long long **)malloc(sizeof(long long *) * (1000001));
    for (int i = 0; i <= 1e6; i++)
        cobin[i] = (long long *)malloc(sizeof(long long) * 2);
    cobin[1][1] = cobin[1][0] = 1;
    for (int i = 2; i <= 1e6; i++){
        cobin[i][0] = 4 * cobin[i - 1][0] + cobin[i - 1][1];
        cobin[i][0] %= MOD;
        cobin[i][1] = 2 * cobin[i - 1][1] + cobin[i - 1][0];
        cobin[i][1] %= MOD;
    }
    while (t--){
        int q;
        scanf("%d", &q);
        printf("%lld\n", (cobin[q][0] + cobin[q][1]) % MOD);
    }
    return 0;
}