#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

void hanoi(int from, int to, int mid, int i){
    if (i == 1){
        printf("%d %d\n", from, to);
        return;
    }
    hanoi(from, mid, to, i - 1);
    hanoi(from, to, mid, 1);
    hanoi(mid, to, from, i - 1);
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", (int)pow(2, n) - 1);
    hanoi(1, 3, 2, n);
    return 0;
}