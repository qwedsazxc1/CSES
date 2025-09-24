#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, INF));
    vector<pair<int, int>> dir = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    while (!q.empty()){
        auto [pos, dist] = q.front();
        q.pop();
        int x = pos.first;
        int y = pos.second;
        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != INF){
            continue;
        }
        grid[x][y] = dist;
        for (auto [dx, dy] : dir){
            q.push({{x + dx, y + dy}, dist + 1});
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << " \n"[j == n - 1];
        }
    }
}