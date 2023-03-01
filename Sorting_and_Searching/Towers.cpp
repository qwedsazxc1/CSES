#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    map<int, int> m;
    for (int i = 0; i < n; i++){
        auto it = m.upper_bound(arr[i]);
        if (it == m.end()){
            m[arr[i]] += 1;
            continue;
        }
        if ((--((*it).second)) == 0)
            m.erase(it);
        m[arr[i]] += 1;
    }
    int sum = 0;
    for (auto p: m)
        sum += p.second;
    cout << sum << "\n";
}