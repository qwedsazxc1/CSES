#include <iostream>
#include <vector>

using namespace std;

void build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr){
    if (l == r)
        return tree[node] = arr[l], void();
    int mid = (r - l) / 2 + 1;
    build(tree, node * 2 + 1, l, mid, arr);
    build(tree, node * 2 + 2, mid + 1, r, arr);
}

void update_add(vector<long long> &tree, int node, int l, int r, int ql, int qr, int x){
    if (l >= ql && r <= qr){
        tree[node] += x;
        return;
    }
    if (r < ql && l > qr){
        tree[node] += tree[(node - 1) / 2];
        return;
    }
    int mid = (r - l) / 2 + 1;
    update_add(tree, node * 2 + 1, l, mid, ql, qr, x + tree[node]);
    update_add(tree, node * 2 + 2, mid + 1, r, ql, qr, tree[node] + x);
    tree[node] = 0;
}

void update();

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<long long> tree(n << 2, 0);
    build(tree, 0, 0, n - 1, arr);
    while (q--){
        int operation;
        cin >> operation;

    }

}