#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1){
        cout << "1\n";
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 1;
    map<int, int> m;
    m[arr[0]];
    for (int i = 1, j = 0; i < n; i++){
        auto it = m.find(arr[i]);
        if (it == m.end()){
            m[arr[i]];
            ans = max(ans, (int)m.size());
            continue;
        }
        while (arr[j] != arr[i]){
            m.erase(arr[j]);
            j++;
        }
        j++;
    }
    cout << ans << "\n";
    return 0;
}