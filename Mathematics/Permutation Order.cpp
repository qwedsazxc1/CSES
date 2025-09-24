#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> fact(21, 1);
    for(int i = 1; i <= 20; i++) 
        fact[i] = fact[i - 1] * i;
    int t;
    cin >> t;
    while(t--){
        int op, n;
        cin >> op >> n;
        if(op == 1){
            ll k;
            cin >> k;
            k--;
            vector<int> ans(n);
            vector<bool> used(n, false);
            for(int i = 0; i < n; i++){
                ll temp = fact[n - 1 - i];
                ll cnt = k / temp;
                k %= temp;
                for(int j = 0; j < n; j++){
                    if(used[j]) continue;
                    if(cnt == 0){
                        ans[i] = j + 1;
                        used[j] = true;
                        break;
                    }
                    cnt--;
                }
            }
            for(int i = 0; i < n; i++){
                cout << ans[i] << " \n"[i == n - 1];
            }
        }
        else{
            vector<int> arr(n);
            for(int i = 0; i < n; i++) 
                cin >> arr[i];
            ll ans = 0;
            vector<bool> used(n, false);
            for(int i = 0; i < n; i++){
                int cnt = 0;
                for(int j = 0; j < arr[i] - 1; j++){
                    if(!used[j]) cnt++;
                }
                ans += cnt * fact[n - 1 - i];
                used[arr[i] - 1] = true;
            }
            cout << ans + 1 << "\n";
        }

    }

    return 0;
}