#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]].push_back(i);
    }
    vector<int> ans(n);
    vector<pair<int, int>> q;
    for (int i = n - 1; i >= 0; i--){
        if (!q.empty()){
            ans[i] = q.back().second;
            q.pop_back();
            continue;
        }
        int l = i;
        for (int j = 0; j < k && i - j >= 0; j++){
            
        }
        
        
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}