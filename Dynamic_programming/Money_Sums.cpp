#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

int min(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int dp[sum + 1];
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = sum; j >= arr[i]; j--){
            dp[j] = min(dp[j], dp[j - arr[i]]);
        }
    }
    int count = 0;
    for (int i = 1; i <= sum; i++){
        if (dp[i] == 0)
            count++;
            
    }
    printf("%d\n", count);
    for (int i = 1; i <= sum; i++){
        if (dp[i] == 0)
            printf("%d ", i);
    }
    return 0;
}

int min(int a, int b){
    return (a > b) ? b : a;
}