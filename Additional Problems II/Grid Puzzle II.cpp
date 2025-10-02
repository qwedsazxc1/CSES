#include <bits/stdc++.h>

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

struct edge{
    int to, inv, cap;
    ll w;
};

int main(){
    int n;
    cin >> n;
    vector<vector<edge>> graph(2 * n + 2);
    auto add_edge = [&](int u, int v, int cap, ll w){
        graph[u].push_back({v, (int)graph[v].size(), cap, w});
        graph[v].push_back({u, (int)graph[u].size() - 1, 0, -w});
    };
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        add_edge(0, i + 1, x, 0);
        sum1 += x;
    }
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        add_edge(n + 1 + i, 2 * n + 1, x, 0);
        sum2 += x;
    }
    if (sum1 != sum2){
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ll w;
            cin >> w;
            add_edge(i + 1, n + 1 + j, 1, -w);
        }
    }

    auto MCMF = [&]() -> pair<ll, ll> {
        vector<ll> dist(2 * n + 2);
        vector<int> from(2 * n + 2), inq(2 * n + 2), pid(2 * n + 2);
        ll flow = 0, cost = 0;
        while (1){
            queue<int> q;
            fill(dist.begin(), dist.end(), INF);
            fill(from.begin(), from.end(), -1);
            fill(inq.begin(), inq.end(), 0);
            q.push(0);
            dist[0] = 0;
            inq[0] = 1;
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                inq[cur] = 0;
                for (int i = 0; i < (int)graph[cur].size(); i++){
                    auto &e = graph[cur][i];
                    if (e.cap > 0 && dist[e.to] > dist[cur] + e.w){
                        dist[e.to] = dist[cur] + e.w;
                        from[e.to] = cur;
                        pid[e.to] = i;
                        if (!inq[e.to]){
                            inq[e.to] = 1;
                            q.push(e.to);
                        }
                    }
                }
            }
            if (from[2 * n + 1] == -1)
                break;
            ll f = INF;
            for (int cur = 2 * n + 1; cur != 0; cur = from[cur]){
                int p = from[cur];
                f = min(f, (ll)graph[p][pid[cur]].cap);
            }
            flow += f;
            for (int cur = 2 * n + 1; cur != 0; cur = from[cur]){
                int p = from[cur];
                graph[p][pid[cur]].cap -= f;
                graph[cur][graph[p][pid[cur]].inv].cap += f;
                cost += f * graph[p][pid[cur]].w;
            }
        }
        return {flow, cost};
    };
    auto [flow, cost] = MCMF();
    if (flow != sum1){
        cout << "-1\n";
        return 0;
    }

    vector<vector<int>> ans(n, vector<int>(n));
    cout << -cost << "\n";
    for (int i = 0; i < n; i++){
        for (auto &e : graph[i + 1]){
            if (e.to != 0 && e.cap == 0){
                ans[i][e.to - n - 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << (ans[i][j] ? "X" : ".");
        }
        cout << "\n";
    }
    return 0;
}