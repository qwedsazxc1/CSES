#include <iostream>
#include <vector>
#include <set>

using namespace std;

int mex(vector<int> &arr){
    set<int> s;
    for (auto x: arr)
        s.insert(x);
    for (int i = 0; i < 1e6 + 5; i++){
        if (s.find(i) == s.end())
            return i;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    vector<int> status(2005);
    status[0] = status[1] = status[2] = 0;
    for (int i = 3; i < 2000; i++){
        vector<int> temp;
        for (int j = 1; j < i - j; j++){
            temp.push_back(status[j] ^ status[i - j]);
        }
        status[i] = mex(temp);
    }
    while (t--){
        int n;
        cin >> n;
        if (n >= 2000)
            cout << "first\n";
        else{
            if (status[n] == 0)
                cout << "second\n";
            else
                cout << "first\n";
        }
            
    }
    return 0;
}