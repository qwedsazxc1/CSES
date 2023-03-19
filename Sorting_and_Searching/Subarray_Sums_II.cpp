#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    long long prefix = 0, x, ans = 0;
    cin >> n >> x;
    map<long long, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++){
        long long input;
        cin >> input;
        prefix += input;
        ans += m[prefix - x];
        m[prefix] += 1;
    }
    cout << ans << "\n";
    return 0;
}