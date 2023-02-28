#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b);
        
        if (b * 2 < a){
            cout << "NO\n";
            continue;
        }
        int sub = a - b;
        b -= sub;
        if (b % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}