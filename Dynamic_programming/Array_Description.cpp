#include <iostream>

#define MOD ((int)1e9 + 7)

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[n][m + 2] = {};
    if (arr[0] == 0)
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    else
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++){
        if (arr[i]){
            dp[i][arr[i]] = ((dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i] + 1]) % MOD + dp[i - 1][arr[i]]) % MOD;
        }
        else{
            for (int j = 1; j <= m; j++)
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD + dp[i - 1][j]) % MOD;
        }
    }
    int sum = 0;

    for (int i = 1; i <= m; i++){
        sum += dp[n - 1][i];
        sum %= MOD;
    }
    printf("%d\n", sum);
    return 0;
}