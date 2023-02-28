#include <iostream>
#include <string.h>
#define MOD ((int)1e9 + 7)
int main(){
    int n;
    scanf("%d", &n);
    int dp[n][n];
    memset(dp, -1, sizeof(int) * n * n);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char input;
            scanf(" %c", &input);
            if (input == '*'){
                dp[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (dp[i][j]){
                
                if (i == 0 && j == 0)
                    continue;
                if (i == 0){
                    dp[i][j] = dp[i][j - 1];
                    continue;
                }
                if (j == 0){
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

    printf("%d\n", dp[n - 1][n - 1]);
}