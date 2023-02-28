#include <iostream> 
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &tree, int node, int weight, vector<int> &dis, vector<bool> &visited){
    if (visited[node])
        return;
    visited[node] = true;
    dis[node] = weight;
    for (auto adj: tree[node])
        dfs(tree, adj, weight + 1, dis, visited);
}

int main(){
    int n;
    cin >> n;
    vector<int> dis(n, 0x3f3f3f3f);
    vector<int> ref(n, 0);
    vector<vector<int>> tree(n); 
    vector<bool> visited(n, false);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ref[a] += 1;
        ref[b] += 1;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int root;
    for (int i = 0; i < n; i++)
        if (ref[i] == 1){
            root = i;
            break;
        }
    
    dfs(tree, root, 0, dis, visited);


}