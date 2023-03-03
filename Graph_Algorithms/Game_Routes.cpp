#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MOD ((long long)1e9 + 7)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        in_degree[b] += 1;
    }
    vector<int> order;
    queue<int> q;
    order.reserve(n);
    for (int i = 0; i < n; i++){
        if (in_degree[i] == 0)
            q.push(i);
    }
    while (!q.empty()){
        int node = q.front();
        order.push_back(node);
        q.pop();
        for (auto x : graph[node]){
            in_degree[x] -= 1;
            if (in_degree[x] == 0)
                q.push(x);
        }
    }
    vector<long long> combination(n, 0);
    combination[0] = 1;
    for (auto node: order){
        for (auto neighbor: graph[node]){
            combination[neighbor] += combination[node];
            combination[neighbor] %= MOD;
        }
    }
    cout << combination[n - 1] << "\n";
    return 0;
}
