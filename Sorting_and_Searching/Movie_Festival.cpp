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
        int l, r;
        cin >> l >> r;
        arr[i] = make_pair(r, l);
    }
    sort(arr.begin(), arr.end());
    int l = 0, ans = 0;
    for (auto p: arr){
        if (p.second >= l){
            ans++;
            l = p.first;
        }
    }
    cout << ans << "\n";
    return 0;
}