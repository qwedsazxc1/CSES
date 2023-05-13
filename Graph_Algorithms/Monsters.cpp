#include <bits/stdc++.h>
#define x first
#define y second
#define INF 0x3f3f3f3f
using namespace std;


vector<vector<int>> graph;
vector<vector<bool>> visited;
typedef pair<int, int> pii;

bool dfs(pii cur, vector<char> &path, int depth = 0){
	if (graph[cur.x][cur.y] <= depth || visited[cur.x][cur.y])
		return false;
	visited[cur.x][cur.y] = true;
	if (cur.x == 0 || cur.y == 0 || cur.x == graph.size() - 1 || cur.y == graph[0].size() - 1)
		return true;
	path.push_back('U');
	if (dfs({cur.x - 1, cur.y}, path, depth + 1))
		return true;
	path.pop_back();
	path.push_back('D');
	if (dfs({cur.x + 1, cur.y}, path, depth + 1))
		return true;
	path.pop_back();
	path.push_back('R');
	if (dfs({cur.x, cur.y + 1}, path, depth + 1))
		return true;
	path.pop_back();
	path.push_back('L');
	if (dfs({cur.x, cur.y - 1}, path, depth + 1))
		return true;
	path.pop_back();
	visited[cur.x][cur.y] = false;
	return false;
}

int main(){
	int n, m;
	cin >> n >> m;
	graph.assign(n, vector<int> (m, INF));
	visited.assign(n, vector<bool> (m, false));
	pii start;
	queue<pair<int, pii>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			char input;
			cin >> input;
			if (input == '#')
				graph[i][j] = -1;
			if (input == 'A'){
				start.x = i; start.y = j;
			}
			if (input == 'M'){
				q.push({0, {i, j}});
			}
		}
	while (!q.empty()){
		int w = q.front().first;
		pii locate = q.front().second;
		q.pop();
		int x = locate.x, y = locate.y;
		if (x < 0 || y < 0 || x >= n || y >= m)
			continue;
		if (visited[x][y])
			continue;
		visited[x][y] = true;
		if (graph[x][y] == -1)
			continue;
		graph[x][y] = w;
		q.push({w + 1, {x + 1, y}});
		q.push({w + 1, {x, y + 1}});
		q.push({w + 1, {x - 1, y}});
		q.push({w + 1, {x, y - 1}});
	}
	visited.assign(n, vector<bool>(m, false));
	vector<char> path;
	bool res = dfs(start, path);
	if (res){
		cout << "YES\n";
		cout << path.size() << "\n";
		for (auto &c: path)
			cout << c;
		cout << "\n";
	}
	else{
		cout << "NO\n";
	}
}
