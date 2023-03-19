#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        indegree[b] += 1;
    }

    vector<int> dp(n, INT_MIN);
    vector<int> from(n, -1);
    dp[0] = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (auto x: graph[node]){
            indegree[x] -= 1;
            if (indegree[x] == 0)
                q.push(x);
            if (dp[node] == INT_MIN)
                continue;
            if (dp[x] < dp[node] + 1){
                dp[x] = dp[node] + 1;
                from[x] = node;
            }
        }
    }
    if (dp[n - 1] == INT_MIN)
        cout << "IMPOSSIBLE\n";
    else{
        stack<int> path;
        path.push(n - 1);
        int node = n - 1;
        while (from[node] != -1){
            path.push(from[node]);
            node = from[node];
        }
        cout << path.size() << "\n";
        while (!path.empty()){
            cout << path.top() + 1 << " ";
            path.pop();
        }
        cout << "\n";
    }
    return 0;
}