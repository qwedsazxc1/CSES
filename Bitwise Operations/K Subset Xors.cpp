#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<int> basis(maxn, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        for (int j = maxn - 1; j >= 0; j--){
            if (arr[i] & (1 << j)){
                if (basis[j] == -1){
                    basis[j] = i;
                    cnt++;
                    break;
                }
                arr[i] ^= arr[basis[j]];
            }
        }
    }
    vector<int> ans;
    ans.reserve(k);
    for (int mask = 0; mask < (1 << cnt) && (int)ans.size() < k; mask++){
        int res = 0;
        for (int i = maxn - 1, j = cnt - 1; i >= 0; i--){
            if (basis[i] != -1){
                if ((mask & (1 << j)) && (res & (1 << i)) == 0)
                    res ^= arr[basis[i]];
                if ((mask & (1 << j)) == 0 && (res & (1 << i)) != 0)
                    res ^= arr[basis[i]];
                j--;
            }
        }
        for (int j = 0; j < min(k, 1 << min(n - cnt, maxn)); j++){
            ans.push_back(res);
            if ((int)ans.size() == k)
                break;
        }

        if (ans.size() == k)
            break;
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << " \n"[i == k - 1];
}