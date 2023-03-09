#include <iostream>
#include <vector>

using namespace std;

bool check(vector<long long> &arr, long long guess, long long t);

int main(){
    int n, t;
    cin >> n >> t;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long l = 1, r = 1e18, ans;
    while (l <= r){
        long long mid = (r - l) / 2 + l;
        if (check(arr, mid, t)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}

bool check(vector<long long> &arr, long long guess, long long t){
    long long sum = 0;
    for (long long num :arr){
        sum +=  guess / num;
        if (sum >= t) break;
    }
    return sum >= t;
}