#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if (a == 0 || b == 0){
            if (a == b){
                cout << "YES\n";
                for (int i = 0; i < n; i++){
                    cout << i + 1 << " \n"[i == n - 1];
                }
                for (int i = 0; i < n; i++){
                    cout << i + 1 << " \n"[i == n - 1];
                }
            } 
            else {
                cout << "NO\n";
            }
            continue;
     
        }
        if (a + b > n){
            cout << "NO\n";
            continue;
        }
        int cnt = a + b;
        cout << "YES\n";
        vector<int> p(n);

        for (int i = 0; i < n; i++){
            if (i < cnt){
                if (i < a){
                    p[i] = cnt + i - a + 1;
                }
                else {
                    p[i] = i - a + 1;
                }
            } 
            else {
                p[i] = i + 1;
            }
            cout << p[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; i++){
            cout << i + 1 << " \n"[i == n - 1];
        }
        
    }
}