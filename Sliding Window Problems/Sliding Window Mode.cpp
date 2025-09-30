#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int, int> m;
    for (int i = 0; i < k; i++) {
        m[arr[i]]++;
    }
    set<pair<int, int>> s;
    for (auto [x, y] : m) {
        s.insert({-y, x});
    }
    cout << s.begin()->second << " \n"[n == k];
    for (int i = k; i < n; i++) {
        if (arr[i] == arr[i - k]) {
            cout << s.begin()->second << " \n"[i == n - 1];
            continue;
        }
        s.erase({-m[arr[i - k]], arr[i - k]});
        s.erase({-m[arr[i]], arr[i]});
        m[arr[i - k]]--;
        if (m[arr[i - k]] > 0) {
            s.insert({-m[arr[i - k]], arr[i - k]});
        }
        m[arr[i]]++;
        s.insert({-m[arr[i]], arr[i]});
        cout << s.begin()->second << " \n"[i == n - 1];
    }
    return 0;
}