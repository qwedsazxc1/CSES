#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char map[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &map[i][j]);
    
    stack<pair<int, int>> s;
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j] == '#')
                continue;
            s.push(make_pair(i, j));
            count++;
            while (!s.empty()){
                pair<int, int> temp = s.top();
                s.pop();
                if (map[temp.first][temp.second] == '#')
                    continue;
                map[temp.first][temp.second] = '#';
                if (temp.first + 1 < n)
                    s.push(make_pair(temp.first + 1, temp.second));
                if (temp.second + 1 < m)
                    s.push(make_pair(temp.first, temp.second + 1));
                if (temp.first - 1 >= 0)
                    s.push(make_pair(temp.first - 1, temp.second));
                if (temp.second - 1 >= 0)
                    s.push(make_pair(temp.first, temp.second - 1));
            }
        }
    }
    printf("%d\n", count);
    return 0;
}