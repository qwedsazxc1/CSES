#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int previous, vector<int> &path){
    visited[node] = true;
    path.push_back(node);
    for (auto num: graph[node]){
        if (num == previous)
            continue;
        if (visited[num]){
            path.push_back(num);
            return 1;
        }
        if (dfs(graph, visited, num, node, path))
            return 1;
    }
    path.pop_back();
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> path;
    path.reserve(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++){
        if (visited[i])
            continue;
        if (dfs(graph, visited, i, i, path)){
            vector<int> ans;
            ans.reserve(n);
            int start_node = path[path.size() - 1];
            ans.push_back(start_node);
            for (int i = path.size() - 2; i >= 0; i--){
                if (path[i] == start_node){
                    ans.push_back(path[i]);
                    break;
                }
                ans.push_back(path[i]);

            }
            cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); i++){
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}