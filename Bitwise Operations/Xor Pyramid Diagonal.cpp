#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n);
    for (int i = 0; i < n; i++){
        dp[i] = arr[i];
    }
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < n; j++){
            if (j & (1 << i))
                dp[j] ^= dp[j ^ (1 << i)];
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = dp[i];
        cout << ans[i] << " \n"[i == n - 1];
    }
}