#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> customer;
    customer.reserve(2 * n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        customer.emplace_back(a, 1);
        customer.emplace_back(b, -1);
    }
    sort(customer.begin(), customer.end());
    int ans = 0, now = 0;
    for (int i = 0; i < 2 * n; i++){
        now += customer[i].second;
        ans = max(ans, now);
    }
    cout << ans << "\n";
    return 0;
}