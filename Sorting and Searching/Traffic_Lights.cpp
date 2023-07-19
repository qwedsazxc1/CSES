#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    map<int, int> weight, index;
    index[n] = n;
    weight[n] = 1;
    while (q--){
        int req;
        cin >> req;
        auto it = index.lower_bound(req);
        int origin_len = (*it).second;
        (*it).second = (*it).first - req;
        weight[origin_len] -= 1;
        if (weight[origin_len] == 0)
            weight.erase(origin_len);
        weight[(*it).second] += 1;
        origin_len -= ((*it).first - req);
        weight[origin_len] += 1;
        index[req] = origin_len;
        cout << (*(--weight.end())).first << " ";
    }
    cout << "\n";
    return 0;
}