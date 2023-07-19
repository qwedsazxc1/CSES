#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long sum = arr[0], max_num = arr[0];
    for (int i = 1; i < n; i++){
        if (sum < 0)
            sum = arr[i];
        else
            sum += arr[i];
        max_num = max(max_num, sum);
    }
    cout << max_num << "\n";
    return 0;
}