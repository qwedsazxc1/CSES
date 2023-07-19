#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    map<int, int> m;
    for (int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);
        m[input];
    }
    printf("%d\n", (int)m.size());
    return 0;
}