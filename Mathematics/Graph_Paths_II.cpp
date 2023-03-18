#include <iostream>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f3f3f3f3f

class matrix{
    vector<vector<long long>> arr;
public:
    matrix(int n, int m) {
        arr.assign(n, vector<long long>(m, INF));
    }
    vector<long long> &operator[](int index){
        return arr[index];
    }
    int size(){
        return arr.size();
    }
    matrix operator*(matrix &a){
        matrix ans(arr.size(), a[0].size());
        for (int i = 0; i < arr.size(); i++)
            for (int j = 0; j < a[0].size(); j++)
                for (int k = 0; k < arr[0].size(); k++)
                    ans[i][j] = min(ans[i][j], arr[i][k] + a[k][j]);
        return ans;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    matrix base(n, n), ans(n, 1);
    for (int i = 0; i < m; i++){
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--; b--;
        base[b][a] = min(base[b][a], w);
    }
    ans[0][0] = 0;
    while (k){
        if (k & 1){
            ans = base * ans;
        }
        base = base * base;
        k >>= 1;
    }
    if (ans[n - 1][0] == INF){
        cout << "-1\n";
    }
    else
        cout << ans[n - 1][0] << "\n";
    return 0;
}