#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, stack<int> &path, vector<bool> &global_visited){
    if (global_visited[node])
        return -1;
    global_visited[node] = true;
    visited[node] = true;
    path.push(node);
    for (auto neighbor: graph[node]){
        if (!visited[neighbor]){
            if (dfs(graph, visited, neighbor, path, global_visited) != -1)
                return 0;
        }
        else{
            path.push(neighbor);
            return 0;
        }
    }
    path.pop();
    visited[node] = false;
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<bool> global_visited(n, false);
    for (int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        from--; to--;
        graph[from].push_back(to);
    }
    stack<int> path;
    int cycle = 0;
    for (int i = 0; i < n; i++){
        if (!global_visited[i]){
            if (dfs(graph, visited, i, path, global_visited) != -1){
                cycle = 1;
                break;
            }
        }
    }
    if (!cycle){
        cout << "IMPOSSIBLE\n";
    }
    else{
        vector<int> ans;
        ans.reserve(n);
        int top = path.top();
        do { 
            ans.push_back(path.top());
            path.pop();
        } while (path.top() != top);
        ans.push_back(top);
        cout << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; i--){
            int node = ans[i];
            cout << node + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}