#include <iostream>
#define MOD ((int)1e9 + 7)
int max(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    int sum = (n + 1) * n / 2;
    if (sum & 1){
        printf("0\n");
        return 0;
    }
    sum /= 2;
    int dp[sum + 1] = {};
    dp[0] = 1;
    long long temp = 0;
    for (int j = 1; j <= n; j++){
        for (int i = sum; i >= j; i--){
            dp[i] += dp[i - j];
            if (i == sum)
                temp = dp[i];
            dp[i] %= MOD;
        }
    }
    if (temp > MOD && temp / 2 < MOD)
        dp[sum] = temp;
    printf("%d\n", dp[sum] / 2);
    return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
}