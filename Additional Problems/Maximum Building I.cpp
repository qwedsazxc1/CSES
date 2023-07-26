#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> to_top(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char in;
			cin >> in;
			if (in == '.'){
				to_top[i][j] = 1;
				if (i != 0)
					to_top[i][j] += to_top[i - 1][j];
			}
			else
				to_top[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		stack<int> s;
		vector<int> res = to_top[i];
		for (int j = 0; j < m; j++){
			while (!s.empty() && to_top[i][s.top()] >= to_top[i][j])
				s.pop();
			int index = -1;
			if (!s.empty())
				index = s.top();
			res[j] += (j - index - 1) * to_top[i][j];
			s.push(j);
		}
		while (!s.empty()) s.pop();
		for (int j = m - 1; j >= 0; j--){
			while (!s.empty() && to_top[i][s.top()] >= to_top[i][j])
				s.pop();
			int index = m;
			if (!s.empty())
				index = s.top();
			res[j] += (index - j - 1) * to_top[i][j];
			ans = max(res[j], ans);
			s.push(j);
		}
	}
	cout << ans << "\n";
	return 0;
}
