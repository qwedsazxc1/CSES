#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    ll sum = x, ans = 0;
    ll lv = x, rv = x, r = 1;
    while (r < k){
        rv = (rv * a + b) % c;
        sum ^= rv;
        r++;
    }
    ans = sum;
    while (r < n){
        rv = (rv * a + b) % c;
        sum ^= rv;
        sum ^= lv;
        lv = (lv * a + b) % c;
        ans ^= sum;
        r++;
    }
    cout << ans << "\n";
}