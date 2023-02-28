#include <iostream>
#define MOD ((int)1e9 + 7)
int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    int coin[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);
    
    int dp[x + 1] = {1};
    for (int i = 0; i < n; i++)
        for (int j = coin[i]; j <= x; j++){
            dp[j] += dp[j - coin[i]];
            dp[j] %= MOD;
        }
    printf("%d\n", dp[x]);
}