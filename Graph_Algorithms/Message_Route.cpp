#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    int ans;
    vector<int> visited(n, 0);
    queue<pair<int, int>> q;
    vector<int> prev(n);
    prev[0] = -1;
    q.push(make_pair(0, 1));
    visited[0] = 1;
    while (!q.empty()){
        pair<int, int> node_and_distance = q.front();
        q.pop();
        if (node_and_distance.first == n - 1){
            ans = node_and_distance.second;
            break;
        }
        for (auto x: graph[node_and_distance.first]){
            if (!visited[x]){
                prev[x] = node_and_distance.first;
                q.push(make_pair(x, node_and_distance.second + 1));
                visited[x] = 1;
            }
        }
    }
    if (!visited[n - 1]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << "\n";
    int cur = n - 1;
    stack<int> s;
    while (prev[cur] != -1){
        s.push(cur);
        cur = prev[cur];
    }
    s.push(0);
    while (!s.empty()){
        cout << s.top() + 1 << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}