#include <iostream>

using namespace std;

int low_bit(int i){
    return i & (-i);
}

int main(){
    int n;
    cin >> n;
    int out = 0;
    for (int i = 0; i < (1 << n); ){

        // output out in binary
        for (int j = n - 1; j >= 0; j--){
            cout << (((1 << j) & out) >> j);
        }
        cout << "\n";


        i++;
        int temp = low_bit(i);
        out ^= temp;
    }
    return 0;
}