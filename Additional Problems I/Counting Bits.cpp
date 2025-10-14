#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long input, ans = 0, base = 2;
    cin >> input;
    if (input == 1){
        cout << 1 << "\n";
        return 0;
    }
    while (base <= input * 2){
        ans += (input / base) * (base / 2);
        if ((((input % base) + 1) - base / 2) > 0)
            ans += (((input % base) + 1) - base / 2);
        base <<= 1;
    }
    cout << ans << "\n";
    return 0;
}