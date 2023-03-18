#include <iostream>
#include <vector>

#define MOD ((long long)1e9 + 7)

using namespace std;

class matrix{
    vector<vector<long long>> arr;
public:
    matrix(int n, int m){
        arr.assign(n, vector<long long>(m, 0));
    }
    vector<long long> &operator[](int index){
        return arr[index];
    }
    int size(){
        return arr.size();
    }
    matrix operator*(matrix a){
        matrix ans(arr.size(), a[0].size());
        for (int i = 0; i < arr.size(); i++)
            for (int j = 0; j < a[0].size(); j++){
                for (int k = 0; k < arr[0].size(); k++){
                    ans[i][j] += arr[i][k] * a[k][j];
                    ans[i][j] %= MOD;
                }
            }
        return ans;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    matrix base(n, n), ans(n, 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        base[b][a] += 1;
    }
    ans[0][0] = 1;
    while (k){
        if (k & 1){
            ans = base * ans;
        }
        base = base * base;
        k >>= 1;
    }
    cout << ans[n - 1][0] << "\n";
    return 0;
}