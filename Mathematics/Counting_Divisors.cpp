#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x_max = 1e6 + 5;
    vector<int> div(x_max, 1);
    for (int i = 2; i <= x_max; i++)
        for (int j = i; j <= x_max; j+= i)
            div[j] += 1;
    int q;
    cin >> q;
    while (q--){
        int req;
        cin >> req;
        cout << div[req] << "\n";
    }
    return 0;
}