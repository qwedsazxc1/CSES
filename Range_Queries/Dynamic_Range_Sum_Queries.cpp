#include <iostream>
#include <vector>

using namespace std;

// 0 base summary segment tree
// l close, r close

long long build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr);
long long query(vector<long long> &tree, int node, int l, int r, int ql, int qr);
long long update(vector<long long> &tree, int node, int l, int r, int k, int u);

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> tree(n << 2, 0);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(tree, 0, 0, n - 1, arr);
    while (q--){
        int operation, a, b;
        cin >> operation >> a >> b;
        a--;
        if (operation == 2){
            
            b--;
            cout << query(tree, 0, 0, n - 1, a, b) << "\n";
            continue;
        }
        update(tree, 0, 0, n - 1, a, b);
    }
}

long long build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr){
    if (l == r){
        return tree[node] = arr[l];
    }
    int mid = (r - l) / 2 + l;
    return tree[node] = build(tree, node * 2 + 1, l, mid, arr) + build(tree, (node + 1) * 2, mid + 1, r, arr);
}

long long query(vector<long long> &tree, int node, int l, int r, int ql, int qr){
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (r - l) / 2 + l;
    return query(tree, node * 2 + 1, l, mid, ql, qr) + query(tree, node * 2 + 2, mid + 1, r, ql, qr); 
}

long long update(vector<long long> &tree, int node, int l, int r, int k, int u){
    if (l > k || r < k)
        return tree[node];
    if (l == r){
        return tree[node] = u;
    }
    int mid = (r - l) / 2 + l;
    return tree[node] = update(tree, node * 2 + 1, l, mid, k, u) + update(tree, node * 2 + 2, mid + 1, r, k, u);
}