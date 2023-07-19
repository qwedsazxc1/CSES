#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) >> 1;
    if (sum & 1){
        cout << "NO\n";
        return 0;
    }
    sum >>= 1;
    vector<long long> v1, v2;
    for (long long i = n; i > 0; i--){
        if (sum >= i){
            v1.push_back(i);
            sum -= i;
        }
        else
            v2.push_back(i);
    }

    cout << "YES\n";
    cout << v1.size() << "\n";
    for (auto it = v1.rbegin(); it != v1.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    cout << v2.size() << "\n";
    for (auto it = v2.rbegin(); it != v2.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";
    return 0;
}