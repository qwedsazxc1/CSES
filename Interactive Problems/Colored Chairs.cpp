#include <bits/stdc++.h>

using namespace std;

int query(int x){
    cout << "? " << x << endl;
    char res;
    cin >> res;
    return res == 'R';
}

int main(){
    int n;
    cin >> n;
    int temp1 = query(1), temp2 = query(n / 2 + 1);
    int ans;
    int l, r, lc;
    int len = n / 2 - 1;
    if (temp1 ^ temp2 ^ (len & 1)){
        ans = n / 2 + 1;
        l = n / 2 + 2, r = n, lc = temp2;
    } else {
        ans = 1;
        l = 2, r = n / 2, lc = temp1;
    }
    while (l <= r){
        int mid = (l + r) / 2;
        int len = mid - l;
        int cur = query(mid);
        if (cur ^ lc ^ (len & 1)){
            ans = mid;
            l = mid + 1;
            lc = cur;
        } else {
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}