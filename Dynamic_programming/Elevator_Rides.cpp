#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> dp(1 << n, 0x3f3f3f3f), last(1 << n, 0x3f3f3f3f);
    dp[0] = 1;
    last[0] = 0;
    for (int i = 1; i < (1 << n); i++){
        for (int a = 0; a < n; a++){
            if (!(1 << a & i))
                continue;
            int s = i & ~(1 << a);
            if (arr[a] + last[s] <= x){
                if (dp[s] < dp[i] || (dp[s] == dp[i] && last[s] + arr[a] < last[i])){
                    dp[i] = dp[s];
                    last[i] = last[s] + arr[a];
                }
            }
            else{
                if (dp[s] + 1 < dp[i] || (dp[s] + 1 == dp[i] && last[s] > arr[a])){
                    dp[i] = dp[s] + 1;
                    last[i] = arr[a];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}