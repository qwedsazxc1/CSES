#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<ll> nx, ny;
    for (int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        nx.insert(x + y);
        ny.insert(x - y);
        cout << max(*nx.rbegin() - *nx.begin(), *ny.rbegin() - *ny.begin()) << "\n";
    }
}