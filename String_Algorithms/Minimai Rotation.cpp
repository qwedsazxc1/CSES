#include <bits/stdc++.h>

using namespace std;

string minimal_rotation(string& str) {
    string s = str + str;
    int n = str.size();
    int i = 0, j = 1, k = 0;

    while (i < n && j < n && k < n){
        if (s[i + k] == s[j + k]) 
            k++;
        else{
            if (s[i + k] < s[j + k]) 
                j = j + k + 1;
            else 
                i = i + k + 1;
            
            if (i == j) 
                j++;
            
            k = 0;
        }
    }

    int start = min(i, j);
    return s.substr(start, n);
}

int main() {
    string str;
	cin >> str;
    cout << minimal_rotation(str) << "\n";
    return 0;
}

