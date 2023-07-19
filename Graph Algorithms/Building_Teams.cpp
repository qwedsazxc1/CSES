#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> team(n, 0);
    for (int i = 0; i < n; i++){
        if (team[i] != 0)
            continue;
        
        stack<int> s;
        s.push(i);
        team[i] = 1;
        while (!s.empty()){
            int node = s.top();
            s.pop();
            for (auto x: graph[node]){
                if (team[x] != 0 && team[x] == team[node]){
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
                if (team[x] == 0){
                    team[x] = (team[node] & 1) + 1;
                    s.push(x);
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << team[i] << " ";
    }
    cout << "\n";
    
    return 0;
}