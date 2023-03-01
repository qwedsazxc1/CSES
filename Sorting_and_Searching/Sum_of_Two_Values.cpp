#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int main(){
    int n, tar;
    cin >> n >> tar;
    map<pair<long long, long long>, long long> m;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        m[make_pair(input, i + 1)] = 1;
    }
    for (auto &p : m){
        p.second -= 1;
        auto it = m.upper_bound(make_pair(tar - p.first.first, n));
        if (it == m.begin()){
            p.second += 1;
            continue;
        }
        
        it--;
        if ((*it).second == 0){
            p.second += 1;
            continue;
        }
        
        if ((*it).first.first != tar - p.first.first){
            p.second += 1;
            continue;   
        }
        
        cout << p.first.second << " " << (*it).first.second << "\n";
        m.clear();
        break;
    }
    if (!m.empty())
        cout << "IMPOSSIBLE\n";
    return 0;
}