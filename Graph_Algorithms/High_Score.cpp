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
    vector<pair<long long, int>> dist(n + 1, make_pair(1e18, 0));
    dist[1].first = 0;
    dist[1].second = 1;

    int flag = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;
            if(dist[u].first + w < dist[v].first){
                dist[v].first = dist[u].first + w;
                dist[v].second = u;
            }
        }
    }

    vector<int> path(n + 1, 0);
    int last = n;
    while (last != 1 && !path[last]){
        path[last] = 1;
        last = dist[last].second;
    }
    if (last != 1){
        cout << -1 << endl;
        return 0;
    }

    cout << -dist[n].first << endl;
    return 0;
}