#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int, int> m;
    for (int i = 0; i < k; i++){
        m[arr[i]]++;
    }
    set<pair<int, int>> s;
    int prev = -1, l = -1;
    for (auto [x, y] : m){
        if (prev == -1){
            l = x;
            prev = x;
            continue;
        }
        if (x == prev + 1){
            prev = x;
            continue;
        }
        s.insert({l, prev});
        l = x;
        prev = x;
    }
    s.insert({l, prev});
    auto find = [&]() -> int {
        if (s.begin()->first != 0) return 0;
        return s.begin()->second + 1;
    };

    cout << find() << "\n";
    for (int i = k; i < n; i++){
        if (arr[i] == arr[i - k]){
            cout << find() << "\n";
            continue;
        }
        m[arr[i]]++;
        auto it = s.upper_bound({arr[i] + 1, -1});
        if (it != s.begin()){
            it--;
            if (it->first <= arr[i] && arr[i] <= it->second){
                pair<int, int> cur = *it;
                s.erase(it);
                if (cur.first == arr[i] && cur.second == arr[i]){
                    // do nothing
                } else if (cur.first == arr[i]){
                    s.insert({cur.first + 1, cur.second});
                } else if (cur.second == arr[i]){
                    s.insert({cur.first, cur.second - 1});
                } else {
                    s.insert({cur.first, arr[i] - 1});
                    s.insert({arr[i] + 1, cur.second});
                }
            }
    }
}