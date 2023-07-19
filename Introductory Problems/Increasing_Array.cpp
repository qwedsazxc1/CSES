#include<iostream>
using namespace std;
typedef long long ll;
void solved(){
    int n;
    scanf("%d", &n);
    ll ans=0;
    int input;
    int prev = 0;
    for (int i = 0; i < n;i++){
        scanf("%d", &input);
        if(prev>input){
            ans += prev - input;
        }else
            prev = input;
    }
    printf("%lld", ans);
}
int main(){
    solved();
    return 0;
}