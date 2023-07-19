#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
void solved();
int main(){
    solved();
    return 0;
}
void solved(){
    int n;
    scanf("%d", &n);
    int array[n];
    memset(array, 0, sizeof(int) * n);
    for (int i = 0; i < n - 1;i++){
        int input;
        scanf("%d", &input);
        array[input - 1] = 1;
    }
    for (int i = 0; i < n ;i++){
        
        if(array[i] == 0){
            printf("%d", i + 1);
            break;
        }
    }
}