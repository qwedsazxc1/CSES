#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

vector<int> tree;


// 0 base segment tree
// l close, r close

int build(int node, int l, int r, vector<int> &arr){
    if (l == r){
        return tree[node] = arr[l];
    }
    int mid = (r - l) / 2 + l;
    return tree[node] = min(build(node * 2 + 1, l, mid, arr), build(2 * (node + 1), mid + 1, r, arr));
}

int query(int node, int l, int r, int ql, int qr){
    if (l > qr || r < ql){
        return INF;
    }
    if (l >= ql && r <= qr){
        return tree[node];
    }
    int mid = (r - l) / 2 + l; 
    return min(query(node * 2 + 1, l, mid, ql, qr), query(2 * (node + 1), mid + 1, r, ql, qr));
}

int main(){
    int n, q;
    cin >> n >> q;
    tree.assign(n << 2, INF);
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    build(0, 0, n - 1, arr);
    while (q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(0, 0, n - 1, a, b) << "\n";
    }
    return 0;
}