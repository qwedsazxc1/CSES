#include <iostream>
#include <vector>

struct Edge{
    int u, v;
    long long w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
};

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        w = -w;
        edges.push_back(Edge(u, v, w));
    }
    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;


    int flag = 0;
    for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;
            if (dist[u] != 1e18 && dist[u] + w < dist[v]){
                if (i >= n){
                    dist[v] = (long long)-1e18;
                    continue;
                }
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << ((dist[n] == (long long)-1e18) ? -1LL : -dist[n]) << endl;
    return 0;
}