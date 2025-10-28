#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tri(ll x){
    return x * (x + 1) >> 1;
}

int istri(ll x){
    return tri(sqrt(x << 1)) == x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll x;
        cin >> x;
        if (istri(x)){
            cout << "1\n";
            continue;
        }
        bool flag = false;
        for (ll i = 1; tri(i) <= x; i++){
            ll rem = x - tri(i);
            if (istri(rem)){
                cout << "2\n";
                flag = true;
                break;
            }
            if (rem <= tri(i)){
                break;
            }
        }
        if (!flag){
            cout << "3\n";
        }
    }
}