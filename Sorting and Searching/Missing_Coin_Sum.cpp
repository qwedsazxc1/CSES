#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long sum = 1;
    for (long long num: arr){
        if (sum < num)
            break;
        
        sum += num;
    }
    cout << sum << "\n";
    return 0;
}