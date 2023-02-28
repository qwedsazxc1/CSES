#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n == 1){
        cout << "0\n";
        return 0;
    }
    vector<vector<int>> graph(n);
    int a, b;
    for (int i = 0; i < n - 1; i++){
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    vector<int> visited(n, -1);
    stack<int> s;
    s.push(a - 1);
    visited[a - 1] = 0;
    pair<int, int> max_and_index(-1, -1);
    // dfs
    while (!s.empty()){
        int node = s.top();
        s.pop();
        for (auto x: graph[node]){
            if (visited[x] != -1)
                continue;
            visited[x] = visited[node] + 1;
            if (visited[x] > max_and_index.first){
                max_and_index.first = visited[x];
                max_and_index.second = x;
            }
            s.push(x);
        }
    }
    s.push(max_and_index.second);
    visited.assign(n, -1);
    visited[max_and_index.second] = 0;
    max_and_index.second = max_and_index.first = -1;
    
    while (!s.empty()){
        int node = s.top();
        s.pop();
        for (auto x: graph[node]){
            if (visited[x] != -1)
                continue;
            visited[x] = visited[node] + 1;
            if (visited[x] > max_and_index.first){
                max_and_index.first = visited[x];
                max_and_index.second = x;
            }
            s.push(x);
        }
    }
    cout << max_and_index.first << '\n';
    return 0;
}