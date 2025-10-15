#include <bits/stdc++.h>

using namespace std;

using ll = __int128;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++){
        int tx, ty;
        cin >> tx >> ty;
        x[i] = tx;
        y[i] = ty;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll sum = 0;
    vector<ll> prex(n + 1, 0), prey(n + 1, 0);
    for (int i = 0; i < n; i++){
        prex[i + 1] = prex[i] + x[i];
        prey[i + 1] = prey[i] + y[i];
    }
    for (int i = 1; i <= n; i++){
        sum += prex[n] - prex[i - 1] - (n - i + 1) * x[i - 1];
        sum += prey[n] - prey[i - 1] - (n - i + 1) * y[i - 1];
    }
    string ans;
    while (sum > 0){
        ans += (char)('0' + (sum % 10));
        sum /= 10;
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty())
        ans = "0";
    cout << ans << "\n";
}