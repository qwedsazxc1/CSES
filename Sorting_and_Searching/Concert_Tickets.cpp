#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<long long, long long> ticket;
    for (int i = 0; i < n; i++){
        long long input;
        cin >> input;
        ticket[input] += 1;
    }
    while (m--){
        long long req;
        cin >> req;
        map<long long, long long>::iterator it = ticket.upper_bound(req);
        if (it == ticket.begin()){
            cout << "-1\n";
            continue;
        }
        it--;
        cout << (*it).first << "\n";
        (*it).second -= 1;
        if ((*it).second == 0){
            ticket.erase(it);
        }
    }
    return 0;
}