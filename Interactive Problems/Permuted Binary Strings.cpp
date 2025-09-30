#include <bits/stdc++.h>

using namespace std;

vector<int> query(int n, int mask){
    vector<int> arr(n, 0);
    for (int i = 1; i <= n; i++){
        if (i & (1 << mask)){
            arr[i - 1] = 1;
        }
    }
    cout << "? ";
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
    vector<int> res(n);
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        res[i] = temp - '0';
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int bits = 0;
    while ((1 << bits) <= n) 
        bits++;
    vector<vector<int>> res(bits, vector<int>(n));
    for (int i = 0; i < bits; i++){
        res[i] = query(n, i);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        int temp = 0;
        for (int j = 0; j < bits; j++){
            if (res[j][i]){
                temp |= (1 << j);
            }
        
        }
        ans[i] = temp;
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
    cout.flush();
    return 0;
}