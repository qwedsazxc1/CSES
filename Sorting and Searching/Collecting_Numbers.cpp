#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int ans = 0, bound = n;
    for (auto p: arr){
        if (bound > p.second){
            ans++;
        }
        bound = p.second;
    }
    cout << ans << "\n";
    return 0;
}