#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    long long current = 0, ans = 0;
    for (int i = 0; i < n; i++){
        current += arr[i].first;
        ans += arr[i].second - current;
    }
    cout << ans << "\n";
    return 0;
}