// sources: https://cses.fi/problemset/task/1144

// task: You are given n salaries and you have to answer q queries. 
// Each query is described by one character and two integers:
// If the character is '?', you have to answer the sum of the salaries in the range [a,b].
// If the character is '!', you have to change the salary of the employee i to x.

// Input Format
// The first input line has two integers n and q: the number of salaries and queries.
// The second line has n integers s1,s2,…,sn: the salary of each employee.
// Then, there are q lines describing the queries. Each line has a character and two integers a and b: the description of the query.

// Output Format
// Print the answer to each '?'-query.

// Constraints
// 1 <= n,q <= 2*10^5
// 1 <= si <= 10^9
// 1 <= a <= b <= n
// 1 <= i <= n
// 1 <= x <= 10^9

// Example

// Input:
// 5 3
// 3 7 2 2 5
// ? 2 3
// ! 3 6
// ? 2 3

// Output:
// 3
// 2

#include <bits/stdc++.h>
using namespace std;

struct node{
    int count = 0;
    node *l = nullptr, *r = nullptr;
};

node *build(int l, int r, node *node, int k, int x);
int query(int l, int r, node *node, int ql, int qr);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> salaries(n);
    node *root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
        root = build(0, 1e9 + 5, root, salaries[i], 1);
    }
    while (q--){
        char req;
        cin >> req;
        if (req == '?'){
            int a, b;
            cin >> a >> b;
            cout << query(0, 1e9 + 5, root, a, b) << "\n";
        }
        else{
            int k, x;
            cin >> k >> x;
            k--;
            root = build(0, 1e9 + 5, root, salaries[k], -1);
            salaries[k] = x;
            root = build(0, 1e9 + 5, root, x, 1);
        }
    }
    return 0;
}

node *build(int l, int r, node *node, int k, int x){
    if (l > k || r < k)
        return node;
    if (node == nullptr){
        node = new struct node;
    }
    if (l == r){
        node->count += x;
        return node;
    }
    int mid = (r - l) / 2 + l;
    node->l = build(l, mid, node->l, k, x);
    node->r = build(mid + 1, r, node->r, k, x);
    node->count = ((node->l  == nullptr) ? 0 : node->l->count) + ((node->r == nullptr) ? 0 : node->r->count);
    return node;
}

int query(int l, int r, node *node, int ql, int qr){
    if (node == nullptr)
        return 0;
    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
        return node->count;
    int mid = (r - l) / 2 + l;
    return query(l, mid, node->l, ql, qr) + query(mid + 1, r, node->r, ql, qr);
}