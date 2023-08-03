#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	int dp[x + 1] = {}, weight[n], value[n], copy[n];
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	for (int i = 0; i < n; i++)
		cin >> copy[i];

	for (int i = 0; i < n; i++){
		int w = weight[i], v = value[i], count = copy[i];
		for (int j = 0; j < w; j++){
			deque<pair<int, int>> s;
			for (int k = 0; k * w + j <= x; k++){
				int temp = dp[k * w + j] - k * v;
				while (!s.empty() && s.back().first <= temp)
					s.pop_back();
				s.push_back({temp, k});
				if (s.front().second + count < k)
					s.pop_front();
				dp[k * w + j] = s.front().first + v * k;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}
