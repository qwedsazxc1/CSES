#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	for (auto &v: arr)
		for (auto &c: v)
			cin >> c;
	vector<pair<int, int>> que;
	string ans;
	que.push_back({0, 0});
	while (!que.empty()){
		char minv = 'Z';
		for (auto [i, j]: que){
			minv = min(minv, arr[i][j]);
		}
		ans += minv;
		vector<pair<int, int>> temp;
		for (auto [i, j]: que){
			if (arr[i][j] != minv)
				continue;
			arr[i][j] = minv + 1;
			if (i + 1 != n)
				temp.push_back({i + 1, j});
			if (j + 1 != n)
				temp.push_back({i, j + 1});
		}
		que = temp;
	}
	cout << ans << "\n";
}
