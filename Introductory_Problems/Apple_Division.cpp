#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    long long ans = INF;
    for (int i = 0; i < (1 << n); i++){
        long long num = 0;
        for (int j = 0; j < n; j++){
            if (i & (1 << j))
                num += arr[j];
        }

        long long temp = sum - num;
        temp -= num;
        if (temp < 0)
            temp *= -1;
        if (ans > temp)
            ans = temp;
    }
    cout << ans << "\n";
    return 0;
}