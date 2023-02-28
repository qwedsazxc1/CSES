#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    memset(arr, 0, sizeof(int) * (n + 1));
    arr[0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = i - 6; j < i; j++)
            if (j >= 0){
                arr[i] += arr[j];
                arr[i] %= (1000000000 + 7);
            }
    
    printf("%d\n", arr[n]);
    return 0;
}