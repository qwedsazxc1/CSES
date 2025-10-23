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
    for (int i = 0; i < min(n, m); i++){
        if (arr[i][i] == 0){
            for (int j = i + 1; j < n; j++){
                if (arr[j][i] != 0){
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
        if (arr[i][i] == 0)
            continue;
        for (int j = i + 1; j < n; j++){
            if (arr[j][i] != 0){
                ll factor = (arr[j][i] * mod_inverse(arr[i][i])) % MOD;
                for (int k = i; k < m + 1; k++){
                    arr[j][k] = ((arr[j][k] - factor * arr[i][k]) % MOD + MOD) % MOD;
                }
            }
        }
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
    for (int i = min(n, m) - 1; i >= 0; i--){
        ll sum = arr[i][m];
        if (arr[i][i] == 0){
            for (int j = i + 1; j < m; j++){
                if (arr[i][j] != 0){
                    for (int k = 0; k < n; k++){
                        swap(arr[k][i], arr[k][j]);
                    }
                    swaps.push_back({i, j});
                    break;
                }
            }
        }
        for (int j = i + 1; j < m; j++){
            sum = ((sum - arr[i][j] * solution[j]) % MOD + MOD) % MOD;
        }
        solution[i] = (sum * mod_inverse(arr[i][i])) % MOD;
    }
    for (int i = (int)swaps.size() - 1; i >= 0; i--){
        auto t = swaps[i];
        swap(solution[t.first], solution[t.second]);
    }
    for (int i = 0; i < m; i++){
        cout << solution[i] << " ";
    }
    cout << "\n";
    return 0;
}