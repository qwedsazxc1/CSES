#include<iostream>

using namespace std;
void solved();
typedef long long int ll;
signed main(){
    solved();
    return 0;
}
void solved(){
    ll n;
    scanf("%lld", &n);
    while(n!=1){
        printf("%lld ", n);
        if(n%2){
            n = n * 3 + 1;
        }else{
            n /= 2;
            
        }
    }
    printf("%lld ", n);
}