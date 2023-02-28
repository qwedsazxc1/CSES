#include<iostream>
using namespace std;
typedef long long ll;
void solved(){
    ll row, column;
    scanf("%lld%lld", &row, &column);
    ll larger;
    if(row==column&&row==1){
        printf("1\n");
        return;
    }
    if(row>=column){
        larger = row;
        if(larger%2){
            printf("%lld\n", (row - 1) * (row - 1) + column);
        }else{
            printf("%lld\n", row * row - column + 1);
        }
    }else{
        larger = column;
        if(larger%2){
            printf("%lld\n", column * column - row + 1);
        }else{
            printf("%lld\n", (column - 1) * (column - 1) + row);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        solved();
    }
    return 0;
}