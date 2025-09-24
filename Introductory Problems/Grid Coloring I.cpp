#include <bits/stdc++.h>

using namespace std;

void er(set<char> &s, char c){
    if (s.find(c) != s.end()){
        s.erase(c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            set<char> available = {'A', 'B', 'C', 'D'};
            if (i > 0){
                er(available, arr[i - 1][j]);
            }
            if (j > 0){
                er(available, arr[i][j - 1]);
            }
            er(available, arr[i][j]);
            arr[i][j] = *available.begin();
            cout << arr[i][j];
            if (j == m - 1){
                cout << "\n";
            } 
        }
    }
}