#include <bits/stdc++.h>

using namespace std;
const int maxn = 30;
using ll = long long;

int main(){
    int n, k;
    ll x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    ll cnt[maxn] = {0};
    ll lv = x, rv = x, res = 0;
    vector<pair<ll, ll>> arr, arr2;
    for (int i = 0; i < k; i++){
        for (auto &x: arr){
            x = {x.first & ~(rv), x.second};
            if (x.first == 0) 
                continue;
            arr2.push_back(x);
        }
        arr.swap(arr2);
        arr2.clear();
        arr.push_back({rv, i});
        res |= rv;
        rv = (a * rv + b) % c;
    }

    ll ans = 0;
    ans ^= res;
    for (int i = k; i < n; i++){
        res |= rv;
        for (auto &x: arr){
            x = {x.first & ~(rv), x.second};
            if (x.first == 0) 
                continue;
            if (x.second == i - k){
                res &= ~(x.first);
                continue;
            }
            arr2.push_back(x);
        }
        arr.swap(arr2);
        arr2.clear();
        arr.push_back({rv, i});
        ans ^= res;
        rv = (a * rv + b) % c;
    }
    cout << ans << "\n";
}