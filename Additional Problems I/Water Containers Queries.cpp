#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int a, b, x;
        cin >> a >> b >> x;
        if (x <= a && (x % gcd(a, b)) == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}