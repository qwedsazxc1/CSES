#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<bool> status(n + 1, false);
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n; i++){
        if (status[i])
            continue;
        for (auto x: arr){
            if (x + i > n)
                break;
            status[x + i] = true;
        }
    }
    for (int i = 1; i <= n; i++){
        if (status[i])
            cout << 'W';
        else
            cout << 'L';
    }
    cout << "\n";
    return 0;
}