// source: https://cses.fi/problemset/task/1749
// author: keep1earning
// title: List Removals
// status: solved

// Problem: List Removals
// Problem Link: https://cses.fi/problemset/task/1749

// this is a segment tree problem

// input
// 5
// 1 2 3 4 5
// 3 1 3 1 1

// output
// 3 1 5 2 4

#include <iostream>
#include <vector>

using namespace std;

int build(vector<int> &tree, int node, int l, int r){
    if (l == r)
        return tree[node] = 1;
    
    int mid = (r - l) / 2 + l;
    return tree[node] = build(tree, node * 2 + 1, l, mid) + build(tree, node * 2 + 2, mid + 1, r);
}

int query(vector<int> &tree, int node, int l, int r, int k){
    if (l == r)
        return l;
    
    int mid = (r - l) / 2 + l;
    if (k <= tree[node * 2 + 1])
        return query(tree, node * 2 + 1, l, mid, k);
    else
        return query(tree, node * 2 + 2, mid + 1, r, k - tree[node * 2 + 1]);
}

int update(vector<int> &tree, int node, int l, int r, int k){
    if (r < k || k < l)
        return tree[node];
    
    if (l == r)
        return tree[node] = 0;
    
    int mid = (r - l) / 2 + l;
    return tree[node] = update(tree, node * 2 + 1, l, mid, k) + update(tree, node * 2 + 2, mid + 1, r, k);
}

int main(){
    // input
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // space for segment tree
    vector<int> tree(4 * n, 0);

    // build segment tree
    build(tree, 0, 0, n - 1);

    for (int i = 0; i < n; i++){
        int q;
        cin >> q;
        int offset = query(tree, 0, 0, n - 1, q);
        cout << arr[offset] << ' ';
        update(tree, 0, 0, n - 1, offset);
    }
    
    cout << '\n';
    return 0;
}