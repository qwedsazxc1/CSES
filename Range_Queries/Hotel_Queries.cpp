#include <iostream>
#include <vector>

using namespace std;

// maximum segment tree
// 0 base
// l close, r close

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr);
int query(vector<int> &tree, int node, int l, int r, int value);
int update(vector<int> &tree, int node, int l, int r, int k, int u);

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> tree(n << 2, 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(tree, 0, 0, n - 1, arr);
    while (q--){
        int a;
        cin >> a;
        int result = query(tree, 0, 0, n - 1, a);
        cout << result + 1 << "\n";
        if (result != -1)
            update(tree, 0, 0, n - 1, result, -a);
    }
    return 0;
}

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr){
    if (l == r)
        return tree[node] = arr[l];
    int mid = (r - l) / 2 + l;
    return tree[node] = max(build(tree, node * 2 + 1, l, mid, arr), build(tree, node * 2 + 2, mid + 1, r, arr));
}

int query(vector<int> &tree, int node, int l, int r, int value){
    if (tree[node] < value)
        return -1;
    if (l == r)
        return l;
    int mid = (r - l) / 2 + l;
    if (tree[node * 2 + 1] >= value)
        return query(tree, node * 2 + 1, l, mid, value);
    else
        return query(tree, node * 2 + 2, mid + 1, r, value);
}

int update(vector<int> &tree, int node, int l, int r, int k, int u){
    if (l > k || r < k)
        return tree[node];
    if (l == r)
        return tree[node] += u;
    int mid = (r - l) / 2 + l;
    return tree[node] = max(update(tree, node * 2 + 1, l, mid, k, u), update(tree, node * 2 + 2, mid + 1, r, k, u));
}