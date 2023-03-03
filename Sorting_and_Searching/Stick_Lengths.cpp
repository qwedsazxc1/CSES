#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long median = arr[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++){
        if (median - arr[i] < 0)
            ans += arr[i] - median;
        else
            ans += median - arr[i];
    }
    cout << ans << "\n";
    return 0;
}