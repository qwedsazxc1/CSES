#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

int min(int a, int b);

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int dp[n + 1][m + 1];
    
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= m; i++)
        dp[1][i] = i - 1;
    for (int i = 1; i <= n; i++)
        dp[n][1] = i - 1;
    for (int i = 0; i <= n && i <= m; i++)
        dp[i][i] = 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

int min(int a, int b){
    return (a > b) ? b : a;
}