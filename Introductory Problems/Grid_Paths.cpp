#include <bits/stdc++.h>

using namespace std;

string path;

bool visited[7][7] = {};
int ans = 0;

bool is_valid(int i, int j){
	return !(i < 0 || j < 0 || i >= 7 || j >= 7 || visited[i][j]);
}

void dfs(int i, int j, int count){
	if (count == 49){
		if (i == 6 && j == 0)
			ans++;
		return;
	}
	if (i == 6 && j == 0)
		return;
	if (is_valid(i + 1, j) && is_valid(i - 1, j) && !is_valid(i, j + 1) && !is_valid(i, j - 1)) return;
	if (!is_valid(i + 1, j) && !is_valid(i - 1, j) && is_valid(i, j + 1) && is_valid(i, j - 1)) return;
	
	visited[i][j] = true;
	switch (path[count - 1]){
		case '?':
			if (is_valid(i - 1, j))
				dfs(i - 1, j, count + 1);
			if (is_valid(i + 1, j))
				dfs(i + 1, j, count + 1);
			if (is_valid(i, j - 1))
				dfs(i, j - 1, count + 1);
			if (is_valid(i, j + 1))
				dfs(i, j + 1, count + 1);
			break;
		case 'U':
			if (is_valid(i - 1, j))
				dfs(i - 1, j, count + 1);
			break;
		case 'D':
			if (is_valid(i + 1, j))
				dfs(i + 1, j, count + 1);
			break;
		case 'L':
			if (is_valid(i, j - 1))
				dfs(i, j - 1, count + 1);
			break;
		case 'R':
			if (is_valid(i, j + 1))
				dfs(i, j + 1, count + 1);
			break;
	}
	visited[i][j] = false;
}

int main(){
	cin >> path;
	dfs(0, 0, 1);
	cout << ans << "\n";
	return 0;
}
