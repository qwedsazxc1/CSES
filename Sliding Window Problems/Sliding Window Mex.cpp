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
    int p = -1, l = -1;
    for (auto [x, y] : m){
        if (p == -1){
            l = x;
            p = x;
            continue;
        }
        if (x == p + 1){
            p = x;
            continue;
        }
        s.insert({l, p});
        l = x;
        p = x;
    }
    s.insert({l, p});
    auto find = [&]() -> int {
        if (s.begin()->first != 0) return 0;
        return s.begin()->second + 1;
    };

    cout << find() << " \n"[k == n];
    for (int i = k; i < n; i++){
        if (arr[i] == arr[i - k]){
            cout << find() << " \n"[i == n - 1];
            continue;
        }
        m[arr[i]]++;
        if (m[arr[i]] == 1){
            auto it = s.lower_bound({arr[i], arr[i]});
            int l = arr[i], r = arr[i];
            if (it != s.begin()){
                auto it2 = prev(it);
                if (it2->second + 1 == arr[i]){
                    l = it2->first;
                    s.erase(it2);
                }
            }
            if (it != s.end()){
                if (it->first - 1 == arr[i]){
                    r = it->second;
                    s.erase(it);
                }
            }
            s.insert({l, r});
        }
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0){
            auto it = s.lower_bound({arr[i - k], arr[i - k]});
            int l, r;
            if (it != s.end() && it->first == arr[i - k]){
                l = it->first, r = it->second;
                if (r == arr[i - k]){
                    s.erase(it);
                }
                else{
                    s.erase(it);
                    s.insert({l + 1, r});
                }
                cout << find() << " \n"[i == n - 1];
                continue;
            }
            it--;
            l = it->first, r = it->second;
            if (r == arr[i - k]){
                s.erase(it);
                s.insert({l, r - 1});
            }
            else{
                s.erase(it);
                s.insert({l, arr[i - k] - 1});
                s.insert({arr[i - k] + 1, r});
            }
            
        }
        cout << find() << " \n"[i == n - 1];
    }
}