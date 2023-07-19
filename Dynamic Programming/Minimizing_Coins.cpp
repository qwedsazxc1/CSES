#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

int min(int a, int b){
    if (a > b)
        return b;
    return a;
}

int main(){
    // input
    int n, x;
    scanf("%d%d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    

    int dp[x + 1];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = arr[i]; j <= x; j++){
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    // output
    printf("%d\n", (dp[x] != INF) ? dp[x] : -1);
    return 0;
}