#include<iostream>
using namespace std;
void solved(){
    int n;
    scanf("%d", &n);
    if(n==1){
        printf("1");
        return;
    }
    if(n==2||n==3){
        printf("NO SOLUTION");
        return;
    }
    if(n==4){
        printf("2 4 1 3 ");
        return;
    }
    for (int i = n; i > 0;i-=2){
        printf("%d ", i);
    }
    for (int i = n - 1; i > 0;i-=2){
        printf("%d ", i);
    }
}
int main(){
    solved();
    return 0;
}