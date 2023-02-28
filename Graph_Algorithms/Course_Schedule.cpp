#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ref(n, 0);
    vector<vector<int>> adjency_list(n);
    vector<int> ans;
    for (int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        adjency_list[from].push_back(to);
        ref[to] += 1;
    }
    queue<int> q;
    int cycle = 0;
    for (int i = 0; i < n; i++)
        if (ref[i] == 0)
            q.push(i);
    
    while (!q.empty()){
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto x: adjency_list[front]){
            ref[x] -= 1;
            if (ref[x] == 0)
                q.push(x);
        }
    }
    
    for (int i = 0; i < n; i++){
        if (ref[i] != 0){
            cycle = 1;
            break;
        }
    }
    if (cycle){
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (auto num: ans){
            cout << num + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}