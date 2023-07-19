#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    int p1 = -1, p2, p3;
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            int l = j + 1, r = n - 1, ans = -1;
            int sum = arr[i].first + arr[j].first;
            while (l <= r){
                int mid = (r - l) / 2 + l;
                if (sum + arr[mid].first < x){
                    l = mid + 1;
                }
                else if (sum + arr[mid].first > x){
                    r = mid - 1;
                }
                else{
                    ans = mid;
                    break;
                }
            }
            if (ans != -1){
                p1 = arr[i].second;
                p2 = arr[j].second;
                p3 = arr[ans].second;
                break;
            }
        }
        if (p1 != -1)
            break;
    }

    if (p1 == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << p1 << " " << p2 << " " << p3 << "\n";
    }
    return 0;
}