#include <bits/stdc++.h>
using namespace std;

// source: https://cses.fi/problemset/task/2166

// required: Range Queries

// task:
// You are given an array of n integers, and your task is to process q queries of the following types:
// 1) update the value of an element with index k to u
// 2) what is the maximum subarray prefix sum in the range [a, b]?

// input formmat:
// n q
// a1 a2 ... an
// t1 a1 b1
// t2 a2 b2
// ...
// tq aq bq

// where n is the number of elements in the array
// q is the number of queries
// ai is the ith element of the array
// ti is the type of query
// ai is the left index of the range or the index of the element to be updated
// bi is the right index of the range or the value to update the element to

// constraints:
// 1 <= n, q <= 2 * 10^5
// 1 <= ai, bi <= 10^9
// 1 <= ti <= 2
// 1 <= ai <= bi <= n
// 1 <= k <= n

// output format:
// for each query of type 2, print the maximum subarray sum in the range [ai, bi]

// t is the type of query
// a is the left index of the range
// b is the right index of the range

// t = 1: update the value of the element at index ai to bi
// t = 2: print the maximum subarray sum in the range [ai, bi]

// example:
// input:
// 8 4
// 1 2 -1 3 1 -5 1 4
// 2 2 6
// 1 4 -2
// 2 2 6
// 2 3 4

// output:
// 5
// 2
// 0

// query function returns the maximum subarray sum in the range [a, b]
pair<long long, long long> query(int node, int l, int r, int a, int b, vector<pair<long long, long long>> &tree);

// update updates the value of the element at index k to x
pair<long long, long long> update(int node, int l, int r, int k, int x, vector<long long> &arr, vector<pair<long long, long long>> &tree);

// build builds the segment tree
pair<long long, long long> build(int node, int l, int r, vector<long long> &arr, vector<pair<long long, long long>> &tree);

int main() {
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n is the number of elements in the array
    // q is the number of queries
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);

    // tree is the segment tree
    vector<pair<long long, long long>> tree(n << 2, make_pair(0, 0));

    // input the array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // build the segment tree
    build(0, 0, n - 1, arr, tree);

    // process the queries
    while (q--) {
        int type;
        cin >> type;

        // type 2 queries are range maximum subarray prefix sum queries
        if (type == 2) {
            int a, b;
            cin >> a >> b;

            // 0-indexing
            a--, b--;

            long long out = query(0, 0, n - 1, a, b, tree).second;
            cout << (out > 0 ? out : 0) << '\n';
            continue;
        } 

        // type 1 queries are point update queries
        int k;
        long long x;
        cin >> k >> x;

        // 0-indexing
        k--;

        update(0, 0, n - 1, k, x, tree);
    }
    return 0;
}

// query returns the pair of the sum of the elements in the range [a, b] and the maximum subarray prefix sum in the range [a, b]
pair<long long, long long> query(int node, int l, int r, int a, int b, vector<pair<long long, long long>> &tree) {
    if (l > b || r < a)
        return make_pair(0, 0);
    if (l >= a && r <= b)
        return tree[node];
    int mid = (r - l) / 2 + l;
    pair<long long, long long> left, right, store;
    left = query(node * 2 + 1, l, mid, a, b, tree);
    right = query(node * 2 + 2, mid + 1, r, a, b, tree);
    store.first = left.first + right.first;
    store.second = max(left.second, left.first + right.second);
    return store;
}

// build returns the pair of the sum of the elements in the range [l, r] and the maximum subarray prefix sum in the range [l, r]
// after building the segment tree
pair<long long, long long> build(int node, int l, int r, vector<long long> &arr, vector<pair<long long, long long>> &tree) {
    if (l == r) 
        return tree[node] = make_pair(arr[l], arr[l]);
    int mid = (r - l) / 2 + l;
    pair<long long, long long> left, right, store;
    left = build(node * 2 + 1, l, mid, arr, tree);
    right = build(node * 2 + 2, mid + 1, r, arr, tree);
    store.first = left.first + right.first;
    store.second = max(left.second, left.first + right.second);
    return tree[node] = store;
}

// update returns the pair of the sum of the elements in the range [l, r] and the maximum subarray prefix sum in the range [l, r]
// after updating the value of the element at index k to x
pair<long long, long long> update(int node, int l, int r, int k, long long x, vector<pair<long long, long long>> &tree) {
    if (l > k || r < k)
        return tree[node];
    if (l == r) 
        return tree[node] = make_pair(x, x);
    int mid = (r - l) / 2 + l;
    pair<long long, long long> left, right, store;
    left = update(node * 2 + 1, l, mid, k, x, tree);
    right = update(node * 2 + 2, mid + 1, r, k, x, tree);
    store.first = left.first + right.first;
    store.second = max(left.second, left.first + right.second);
    return tree[node] = store;
}