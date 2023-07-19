#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<string> map(n);
    for (int i = 0; i < n; i++){
        cin >> map[i];
    }
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j] == '*'){
                prefix[i + 1][j + 1] = 1;
            }
        }

    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            prefix[i + 1][j + 1] += prefix[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            prefix[j + 1][i + 1] += prefix[j][i + 1];
        }
    }
    while (q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}