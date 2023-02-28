#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr);
int query(vector<int> &tree, int node, int l, int r, int ql, int qr);
int update(vector<int> &tree, int node, int l, int r, int k, int u);

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> tree(n << 2, INF);
    vector<int> arr(n);
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
    return 0;
}

int build(vector<int> &tree, int node, int l, int r, vector<int> &arr){
    if (l == r)
        return tree[node] = arr[l];
    int mid = (r - l) / 2 + l;
    return tree[node] = min(build(tree, node * 2 + 1, l, mid, arr), build(tree, node * 2 + 2, mid + 1, r, arr));
}

int query(vector<int> &tree, int node, int l, int r, int ql, int qr){
    if (l > qr || r < ql)
        return INF;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (r - l) / 2 + l;
    return min(query(tree, node * 2 + 1, l, mid, ql, qr), query(tree, node * 2 + 2, mid + 1, r, ql, qr));
}

int update(vector<int> &tree, int node, int l, int r, int k, int u){
    if (l > k || r < k)
        return tree[node];
    if (l == r)
        return tree[node] = u;
    int mid = (r - l) / 2 + l;
    return tree[node] = min(update(tree, node * 2 + 1, l, mid, k, u), update(tree, node * 2 + 2, mid + 1, r, k, u));
}