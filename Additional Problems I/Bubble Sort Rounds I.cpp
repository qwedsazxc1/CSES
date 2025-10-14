#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++){
        pos[sorted[i]].push_back(i);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--){
        if (arr[i] == sorted[i]) continue;
        ans = max(ans, i - pos[arr[i]].back());
        pos[arr[i]].pop_back();
    }
    cout << ans << "\n";
    return 0;
}