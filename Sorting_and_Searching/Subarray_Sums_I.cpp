#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    long long tar;
    cin >> n >> tar;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long sum = 0, ans = 0;
    int i = 0;
    for (int j = 0; j < n; ){
        if (sum < tar){
            sum += arr[j++];
            if (sum == tar)
                ans++;
        }
        else {
            sum -= arr[i++];
            if (sum == tar)
                ans++;
        }
    }
    while (sum){
        sum -= arr[i++];
        if (sum == tar)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}