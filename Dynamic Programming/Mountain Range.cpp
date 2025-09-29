#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n + 2, INF);
    int minv = INF;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        minv = min(minv, arr[i]);
    }
    vector<pair<int, int>> order(n);
    for (int i = 1; i <= n; i++)
        order[i - 1] = {arr[i], i};
    vector<int> dp(n + 2, 1);
    sort(order.begin(), order.end());
    vector<int> l(n + 2, -1), r(n + 2, -1);
    for (int i = 0; i < n + 2; i++){
        l[i] = i - 1;
        r[i] = i + 1;
    }
    auto find = [&](auto &self, int a, int x, int dir){
        if (dir == 0){
            if (arr[a] > x)
                return a;
            return l[a] = self(self, l[a], x, dir);
        }
        else{
            if (arr[a] > x)
                return a;
            return r[a] = self(self, r[a], x, dir);
        }
    };
    int ans = 1;
    for (int i = 0; i < n; i++){
        int cur = order[i].second;
        int left = find(find, cur - 1, arr[cur], 0);
        int right = find(find, cur + 1, arr[cur], 1);

        if (arr[left] > arr[cur])
            dp[left] = max(dp[cur] + 1, dp[left]);
        if (arr[right] > arr[cur])
            dp[right] = max(dp[cur] + 1, dp[right]);
        ans = max(ans, dp[cur]);
        l[cur] = left;
        r[cur] = right;
    }
    cout << ans << "\n";
}