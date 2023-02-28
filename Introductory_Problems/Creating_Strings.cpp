#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int fraction(int a){
    if (a == 1 || a == 0)
        return 1;
    return a * fraction(a - 1);
}

int main(){
    string s;
    map<char, int> m;
    cin >> s;
    sort(s.begin(), s.end());
    for (auto c: s){
        m[c]++;
    }
    int number = fraction(s.size());
    for (auto p: m){
        number /= fraction(p.second);
    }
    cout << number << "\n";
    for ( ; ; ){
        cout << s << "\n";
        next_permutation(s.begin(), s.end());
        if (is_sorted(s.begin(), s.end()))
            break;
    }
    return 0;
}