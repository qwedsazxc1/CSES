#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    sort(weight.begin(), weight.end());
    map<pair<long long, long long>, long long> ans;
    for (int i = n - 1; i >= 0; i--){
        if (ans.empty()){
            ans[make_pair(1, weight[i])] += 1;
            continue;
        }
        auto it = ans.upper_bound(make_pair(1, x - weight[i]));
        if (it == ans.begin()){
            ans[make_pair(1, weight[i])] += 1;;
            continue;
        }
        it--;
        int val = (*it).first.second;
        pair<long long, long long> ins_p = make_pair(2, val + weight[i]);
        (*it).second -= 1;
        if ((*it).second == 0)
            ans.erase(it);
        ans[ins_p] += 1;
    }
    long long sum = 0;
    for (auto p: ans){
        sum += p.second;
    }
    cout << sum << "\n";
    return 0;
}