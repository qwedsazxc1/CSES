#include <bits/stdc++.h>
#define MOD ((ll)1e9 + 7)

using namespace std;
using ll = long long;

ll fast_pow(ll base, ll power){
    ll res = 1;
    while (power){
        if (power & 1){
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        power >>= 1;
    }
    return res;
}

ll mod_inverse(ll x){
    return fast_pow(x, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m + 1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m + 1; j++){
            cin >> arr[i][j];
        }
    }
    for (int i = 0, j = 0; i < n && j < m; j++){
        if (arr[i][j] == 0){
            for (int k = i + 1; k < n; k++){
                if (arr[k][j] != 0){
                    swap(arr[i], arr[k]);
                    break;
                }
            }
        }
        if (arr[i][j] == 0)
            continue;
        for (int k = i + 1; k < n; k++){
            if (arr[k][j] != 0){
                ll factor = (arr[k][j] * mod_inverse(arr[i][j])) % MOD;
                for (int l = j; l < m + 1; l++){
                    arr[k][l] = ((arr[k][l] - factor * arr[i][l]) % MOD + MOD) % MOD;
                }
            }
        }
        i++;
    }
    bool flag = true;
    for (int i = 0; i < n; i++){
        bool all_zero = true;
        for (int j = 0; j < m; j++){
            if (arr[i][j] != 0){
                all_zero = false;
                break;
            }
        }
        if (all_zero && arr[i][m] != 0){
            flag = false;
            break;
        }
    }
    if (!flag){
        cout << "-1\n";
        return 0;
    }
    vector<ll> solution(m, 0);
    vector<pair<int, int>> swaps;
    for (int i = n - 1; i >= 0; i--){
        ll sum = arr[i][m];
        ll idx = -1;
        for (int j = 0; j < m; j++){
            if (arr[i][j] != 0){
                idx = j;
                break;
            }
        }
        if (idx == -1)
            continue;
        for (int j = idx + 1; j < m; j++){
            sum = ((sum - arr[i][j] * solution[j]) % MOD + MOD) % MOD;
        }
        solution[idx] = (sum * mod_inverse(arr[i][idx])) % MOD;
    }
    for (int i = 0; i < m; i++){
        cout << solution[i] << " ";
    }
    cout << "\n";
    return 0;
}