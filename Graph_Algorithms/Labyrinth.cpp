#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>

#define FROM_RIGHT 0
#define FROM_UP 1
#define FROM_LEFT 2
#define FROM_DOWN 3
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;    
    vector<vector<char>> map(n, vector<char>(m));
    queue<pair<int, int>> q;
    pair<int, int> final_locate, start;

    // read input and find start and end
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            if (map[i][j] == 'A'){
                start = make_pair(i, j);
                q.push(start);
            }
            if (map[i][j] == 'B')
                final_locate = make_pair(i, j);
        }
    }
    vector<vector<pair<int, int>>> step(n, vector<pair<int, int>>(m, make_pair(0x3f3f3f3f, 0x3f3f3f3f)));
    pair<int, int> temp = q.front();
    step[temp.first][temp.second].first = 0;
    step[temp.first][temp.second].second = -1;

    // bfs
    while (!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        if (map[current.first][current.second] == 'B')
            break;
        if (map[current.first][current.second] == '#')
            continue;
        map[current.first][current.second] = '#';
        if (current.first + 1 < n && map[current.first + 1][current.second] != '#'){

            step[current.first + 1][current.second].first = step[current.first][current.second].first + 1;
            step[current.first + 1][current.second].second = FROM_DOWN;
            q.push(make_pair(current.first + 1, current.second));
        }
        if (current.second + 1 < m && map[current.first][current.second + 1] != '#'){

            step[current.first][current.second + 1].first = step[current.first][current.second].first + 1;
            step[current.first][current.second + 1].second = FROM_LEFT;
            q.push(make_pair(current.first, current.second + 1));
        }
        if (current.first - 1 >= 0 && map[current.first - 1][current.second] != '#'){

            step[current.first - 1][current.second].first = step[current.first][current.second].first + 1;
            step[current.first - 1][current.second].second = FROM_UP;
            q.push(make_pair(current.first - 1, current.second));
        }
        if (current.second - 1 >= 0 && map[current.first][current.second - 1] != '#'){

            step[current.first][current.second - 1].first = step[current.first][current.second].first + 1;
            step[current.first][current.second - 1].second = FROM_RIGHT;
            q.push(make_pair(current.first, current.second - 1));
        }
    }

    // output
    if (step[final_locate.first][final_locate.second].first == 0x3f3f3f3f){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << step[final_locate.first][final_locate.second].first << "\n";
        stack<char> s;
        while (final_locate != start){
            if (step[final_locate.first][final_locate.second].second == FROM_LEFT){
                s.push('R');
                final_locate.second -= 1;
                continue;
            }
            if (step[final_locate.first][final_locate.second].second == FROM_UP){
                s.push('U');
                final_locate.first += 1;
                continue;
            }
            if (step[final_locate.first][final_locate.second].second == FROM_RIGHT){
                s.push('L');
                final_locate.second += 1;
                continue;
            }
            if (step[final_locate.first][final_locate.second].second == FROM_DOWN){
                s.push('D');
                final_locate.first -= 1;
                continue;
            }
        }
        while (!s.empty()){
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    return 0;
}