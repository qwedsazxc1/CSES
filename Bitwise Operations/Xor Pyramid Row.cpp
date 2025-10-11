#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x: arr)
        cin >> x;
    k = n - k;
    const int maxn = 20;
    for (int i = 0; i < maxn; i++){
        if (k & (1 << i)){
            for (int j = 0; j + (1 << i) < n; j++){
                arr[j] ^= arr[j + (1 << i)];
            }
        }
    }
    for (int i = 0; i < n - k; i++)
        cout << arr[i] << " \n"[i == n - k - 1];
}