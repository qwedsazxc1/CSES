#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, unsigned long long>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    map<int, unsigned long long> dp;
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        int st = arr[i].first.second, end = arr[i].first.first;
        unsigned long long w = arr[i].second;
        auto it = dp.lower_bound(st);
        it--;
        unsigned long long prev_w = (*it).second;
        auto check = dp.upper_bound(end);
        check--;
        dp[end] = max(prev_w + w, (*check).second);
    }
    auto it = dp.end();
    it--;
    cout << (*it).second << "\n";
    return 0;
}