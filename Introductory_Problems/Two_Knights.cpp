#include<iostream>
using namespace std;
typedef unsigned long long ull;
void solved(ull i){
    printf("%llu\n", (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2);
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        solved(i);
    }
}