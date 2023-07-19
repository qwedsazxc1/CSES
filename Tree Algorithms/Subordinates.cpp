#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> &sub, vector<vector<int>> &tree, int current){
    if (tree[current].size() == 0){
        sub[current] = 0;
        return 1;
    }
    int count = 0;
    for (auto x: tree[current]){
        count += dfs(sub, tree, x);
    }
    return (sub[current] = count) + 1;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++){
        int input;
        cin >> input;
        tree[input - 1].push_back(i + 1);
    }
    vector<int> sub(n);
    dfs(sub, tree, 0);
    for (auto x: sub){
        cout << x << ' ';
    }
    cout << "\n";
    return 0;
}