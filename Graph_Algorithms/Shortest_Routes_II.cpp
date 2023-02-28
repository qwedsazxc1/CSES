#include <iostream>
#include <vector>

using namespace std;


// This is the same as the previous snippet, but with Floyd-Warshall instead of Dijkstra's.


int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> adj(n, vector<long long>(n, 1e18));
    for (int i = 0; i < m; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;

        // If there are multiple edges between two nodes, take the minimum
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }

    // Set diagonal to 0
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;

    // Floyd-Warshall
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (adj[a][b] == 1e18)
            cout << -1 << endl;
        else
            cout << adj[a][b] << endl;
    }
}