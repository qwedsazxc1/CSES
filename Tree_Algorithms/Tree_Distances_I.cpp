#include <iostream> 
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &tree, int node, int weight, vector<int> &dis, int previous){
    dis[node] = weight;
    int far = -1;
    for (auto adj: tree[node]){
        if (previous != adj){
            int max_node = dfs(tree, adj, weight + 1, dis, node);
            if (far == -1 || (dis[far] < dis[max_node]))
                far = max_node;
        }
    }
    return (far == -1) ? node : far;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> dis(2, vector<int> (n));
    vector<vector<int>> tree(n); 
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    int max_node1 = dfs(tree, 0, 0, dis[0], 0);
    int max_node2 = dfs(tree, max_node1, 0, dis[0], max_node1);
    dfs(tree, max_node2, 0, dis[1], max_node2);

    for (int i = 0; i < n; i++){
        cout << max(dis[0][i], dis[1][i]) << " "; 
    }
    cout << "\n";
    return 0;
}