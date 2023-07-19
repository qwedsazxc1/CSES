#include <iostream>
#define MOD ((int)1e9 + 7)
using namespace std;

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[x + 1] = {1};
    for (int j = 1; j <= x; j++){
        for (int i = 0; i < n; i++)
            if (j >= arr[i]){
                dp[j] += dp[j - arr[i]];
                dp[j] %= MOD;
            }
    }
    
    printf("%d\n", dp[x]);
}