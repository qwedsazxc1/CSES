#include <iostream>
#include <vector>

using namespace std;

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr);
int query(vector<int> &tree, int node, int l, int r, int ql, int qr);

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> tree(n << 2, 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(tree, 0, 0, n - 1, arr);
    while (q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(tree, 0, 0, n - 1, a, b) << "\n";
    }
    return 0;
}

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr){
    if (l == r)
        return tree[node] = arr[l];
    int mid = (r - l) / 2 + l;
    return tree[node] = build(tree, node * 2 + 1, l, mid, arr) ^ build(tree, node * 2 + 2, mid + 1, r, arr);
}

int query(vector<int> &tree, int node, int l, int r, int ql, int qr){
    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (r - l) / 2 + l;
    return query(tree, node * 2 + 1, l, mid, ql, qr) ^ query(tree, node * 2 + 2, mid + 1, r, ql, qr);
}