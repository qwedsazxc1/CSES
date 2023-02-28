#include <iostream>
#include <vector>

using namespace std;

void build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr);
long long query(vector<long long> &tree, int node, int l, int r, int k, long long u);
void update(vector<long long> &tree, int node, int l, int r, int ql, int qr, long long u);

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> tree(n << 2, 0);
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    build(tree, 0, 0, n - 1, arr);
    while (q--){
        int operation;
        cin >> operation;
        if (operation == 2){
            int k;
            cin >> k;
            k--;
            cout << query(tree, 0, 0, n - 1, k, 0) << "\n";
            continue;
        }
        int a, b;
        long long u;
        cin >> a >> b >> u;
        a--;
        b--;
        update(tree, 0, 0, n - 1, a, b, u);
    }
    return 0;
}

void build(vector<long long> &tree, int node, int l, int r, vector<long long> &arr){
    if (l == r){
        tree[node] = arr[l];
        return;
    }
    int mid = (r - l) / 2 + l;
    build(tree, node * 2 + 1, l, mid, arr);
    build(tree, node * 2 + 2, mid + 1, r, arr);
}

long long query(vector<long long> &tree, int node, int l, int r, int k, long long u){
    if (l > k || r < k){
        tree[node] += u;
        return 0;
    }
    if (l == r){
        return tree[node] += u;
    }
    int mid = (r - l) / 2 + l;
    long long ret = query(tree, node * 2 + 1, l, mid, k, u + tree[node]) + query(tree, node * 2 + 2, mid + 1, r, k, u + tree[node]);
    tree[node] = 0;
    return ret;
}

void update(vector<long long> &tree, int node, int l, int r, int ql, int qr, long long u){
    if (l > qr || r < ql){
        return;
    }
    if (l >= ql && r <= qr){
        tree[node] += u;
        return;
    }
    int mid = (r - l) / 2 + l;
    update(tree, node * 2 + 1, l, mid, ql, qr, u);
    update(tree, node * 2 + 2, mid + 1, r, ql, qr, u);
    return;
}