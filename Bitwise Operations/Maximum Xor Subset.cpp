#include <bits/stdc++.h>

using namespace std;
const int maxn = 30;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<int> basis(maxn, -1);
    for (int i = 0; i < n; i++){
        for (int j = maxn - 1; j >= 0; j--){
            if (arr[i] & (1 << j)){
                if (basis[j] == -1){
                    basis[j] = i;
                    break;
                }
                arr[i] ^= arr[basis[j]];
            }
        }
    }
    int ans = 0;
    for (int i = maxn - 1; i >= 0; i--){
        if (basis[i] != -1 && (ans & (1 << i)) == 0)
            ans ^= arr[basis[i]];
    }
            
    cout << ans << "\n";
}