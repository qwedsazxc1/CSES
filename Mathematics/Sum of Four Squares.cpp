#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    const ll maxn = 1e7;
    vector<pair<ll, ll>> squares(maxn + 1, {-1, -1});
    for (ll i = 0; i * i <= maxn; i++){
        for (ll j = i; i * i + j * j <= maxn; j++){
            squares[i * i + j * j] = {i, j};
        }
    }
    int t;
    cin >> t;
    while (t--){
        ll x;
        cin >> x;
        for (ll i = 0; i <= x; i++){
            ll rem = x - i;
            if (squares[rem].first != -1 && squares[i].second != -1){
                ll a = squares[i].first;
                ll b = squares[i].second;
                ll c = squares[rem].first;
                ll d = squares[rem].second;
                cout << a << " " << b << " " << c << " " << d << "\n";
                break;
            }
        }
    }
}