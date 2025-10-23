#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> temp(n);
    vector<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && arr[s.back()] < arr[i]){
            s.pop_back();
        }
        temp[i] = s.empty() ? -1 : s.back();
        s.push_back(i);
    }

    struct node {
        vector<int> arr;
    };
    vector<node> tree(n << 2);
    auto pull = [&](int cur) -> void {
        int ls = tree[cur * 2 + 1].arr.size();
        int rs = tree[cur * 2 + 2].arr.size();
        tree[cur].arr.resize(ls + rs);
        int i = 0, li = 0, ri = 0;
        while (i < ls + rs){
            if (li == ls || (ri != rs && tree[cur * 2 + 2].arr[ri] < tree[cur * 2 + 1].arr[li])){
                tree[cur].arr[i++] = tree[cur * 2 + 2].arr[ri++];
            } else {
                tree[cur].arr[i++] = tree[cur * 2 + 1].arr[li++];
            }
        }
    };
    auto build = [&](auto &self, int cur, int l, int r) -> void {
        if (l == r){
            tree[cur].arr.push_back(temp[l]);
            return;
        }
        int mid = (l + r) >> 1;
        self(self, cur * 2 + 1, l, mid);
        self(self, cur * 2 + 2, mid + 1, r);
        pull(cur);
    };
    build(build, 0, 0, n - 1);
    auto query = [&](auto &self, int cur, int l, int r, int ql, int qr) -> int {
        if (r < ql || l > qr){
            return 0;
        }
        if (ql <= l && r <= qr){
            return lower_bound(tree[cur].arr.begin(), tree[cur].arr.end(), ql) - tree[cur].arr.begin();
        }
        int mid = (l + r) >> 1;
        return self(self, cur * 2 + 1, l, mid, ql, qr) +
               self(self, cur * 2 + 2, mid + 1, r, ql, qr);
    };

    while (q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(query, 0, 0, n - 1, l, r) << '\n';
    }

    return 0;
}