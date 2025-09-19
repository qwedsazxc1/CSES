#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &x: arr)
        cin >> x;
    map<ll, ll> m;
    for (int i = 0; i < k; i++)
        m[arr[i]]++;
    vector<ll> ans(n - k + 1);
    ans[0] = m.size();
    for (int i = k; i < n; i++){
        m[arr[i]]++;
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0){
            m.erase(arr[i - k]);
        }
        ans[i - k + 1] = m.size();
    }
    for (int i = 0; i < n - k + 1; i++)
        cout << ans[i] << " \n"[i == n - k];
}