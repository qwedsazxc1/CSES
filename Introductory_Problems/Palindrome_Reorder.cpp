#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<char, int> dict;
    string str;
    cin >> str;
    for (auto c: str){
        dict[c] += 1;
    }
    int flag = 0;
    char odd = 0;
    for (auto p : dict){
        if ((p.second & 1) & flag){
            cout << "NO SOLUTION\n";
            return 0;
        }
        if (p.second & 1){
            flag = 1;
            odd = p.first;
        }
    }
    for (auto &p: dict){
        if (p.first == odd)
            continue;
        int loop_time = p.second >> 1;
        p.second >>= 1;
        for (int i = 0; i < loop_time; i++)
            cout << p.first;
    }
    while (dict[odd] > 0){
        cout << odd;
        dict[odd]--;
    }
    for (auto it = dict.rbegin(); it != dict.rend(); it++){
        for (int i = 0; i < (*it).second; i++)
            cout << (*it).first;
    }
    cout << "\n";
    return 0;
}