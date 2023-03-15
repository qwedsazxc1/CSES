#include <iostream>
#include <vector>
using namespace std;
#define MOD ((long long)1e9 + 7)


class matrix{
    int size;
public:
    vector<vector<long long>> arr;  
    matrix(int size){
        this->size = size;
        arr.assign(size, vector<long long>(size, 0));
        for (int j = 0; j < size; j++)
            arr[0][j] = 1;
        for (int j = 1; j < size; j++){
            arr[j][j - 1] = 1;
        }
    }
    matrix operator*(matrix another){
        matrix ans(size);
        
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                ans.arr[i][j] = 0;
                for (int k = 0; k < size; k++){
                    ans.arr[i][j] += arr[i][k] * another.arr[k][j];
                }   
            }
        }
        return ans;
    }
    matrix operator%(long long mod){
        matrix ans(size);
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++)
                ans.arr[i][j] = arr[i][j] % mod;
        }
        return ans;
    }
};

int main(){
    long long n;
    cin >> n;
    matrix base(6), ans(6);
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (i == j)
                ans.arr[i][j] = 1;
            else
                ans.arr[i][j] = 0;
    while (n){
        if (n & 1){
            ans = ans * base;
            ans = ans % MOD;
        }
        base = base * base;
        base = base % MOD;
        n >>= 1;
    }
    cout << ans.arr[0][0] << "\n";
    return 0;
}