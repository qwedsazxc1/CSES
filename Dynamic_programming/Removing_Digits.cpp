#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

int min(int a, int b){
    if (a > b)
        return b;
    return a;
}

int main(){
    int n;
    scanf("%d", &n);
    int dp[n + 1];
    memset(dp, INF, sizeof(int) * (n + 1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        int temp = i;  
        while (temp > 0){
            int mod = temp % 10;
            dp[i] = min(dp[i], dp[i - mod] + 1);
            temp /= 10;
        }
    }
    printf("%d\n", dp[n]);
}