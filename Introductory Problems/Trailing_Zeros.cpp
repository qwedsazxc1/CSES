#include <iostream>

int min(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    int count_5 = 0;
    while (n > 0){
        count_5 += n / 5;
        n /= 5;
    }
    printf("%d\n", count_5);
    return 0;
}

int min(int a, int b){
    if (a > b)
        return b;
    return a;
}