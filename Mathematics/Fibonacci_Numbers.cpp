#include <iostream>
#include <vector>
#include <algorithm>
#define MOD ((long long)1e9 + 7)
using namespace std;

vector<vector<long long>> mul(vector<vector<long long>> first, vector<vector<long long>> second){
    vector<vector<long long>> res(first.size(), vector<long long> (second[0].size()));
    for (int i = 0; i < first.size(); i++){
        for (int k = 0; k < second[0].size(); k++){
            long long sum = 0;
            for (int j = 0; j < first[i].size(); j++){
                sum += first[i][j] * second[j][k];
            }
            res[i][k] = sum;
        }
    }
    return res;
}

void mod(vector<vector<long long>> &ans){
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0;  j < ans[i].size(); j++)
            ans[i][j] %= MOD;
}

int main(){
    long long n;
    cin >> n;
    if (n == 1 || n == 0){
        cout << n << "\n";
        return 0;
    }
    vector<vector<long long>> base(2, vector<long long>(2));
    base[0][0] = 1;
    base[0][1] = 1;
    base[1][0] = 1;
    base[1][1] = 0;
    vector<vector<long long>> ans(2, vector<long long>(2));
    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;
    while (n){
        if (n & 1){
            ans = mul(ans, base);
            mod(ans);
        }
        base = mul(base, base);
        mod(base);
        n >>= 1;
    }
    cout << ans[0][1] << "\n";
    return 0;
}