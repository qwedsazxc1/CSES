#include <iostream>

int max(int a, int b);

int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    int book[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d", &book[i][0]);
    for (int i = 0; i < n; i++)
        scanf("%d", &book[i][1]); 

    int dp[x + 1] = {};
    for (int i = 0; i < n; i++){
        for (int j = x; j >= book[i][0]; j--){
            dp[j] = max(dp[j], dp[j - book[i][0]] + book[i][1]);
        }
    }
    printf("%d\n", dp[x]);
}

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}