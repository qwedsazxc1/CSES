#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, ll>> graph[n];
	for (int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v, w});
	}
	vector<ll> dist(n, INF);
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
	pq.push({0, {0, 0}});
	vector<int> from[n];
	while (!pq.empty()){
		auto t = pq.top();
		pq.pop();
		int cur = t.second.first, prev = t.second.second;
		ll w = t.first;
		if (dist[cur] < w)
			continue;
		from[cur].push_back(prev);
		if (dist[cur] != INF)
			continue;
		dist[cur] = w;
		for (auto next: graph[cur]){
			pq.push({w + next.second, {next.first, cur}});
		}
	}
	vector<double> dp(n);
	dp[n - 1] = 1;
	priority_queue<pair<ll, int>> pq2;
	vector<bool> vis(n, false);
	pq2.push({dist[n - 1], n - 1});
	while (!pq2.empty()){
		auto t = pq2.top();
		pq2.pop();
		int cur = t.second;
		if (vis[cur])
			continue;
		vis[cur] = true;
		if (cur == 0)
			break;
		double w = dp[cur] / (double)from[cur].size();
		for (auto next: from[cur]){
			dp[next] += w;
			pq2.push({dist[next], next});
		}
	}

	double diff = 1e-6;
	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (1 + diff >= dp[i] && dp[i] >= 1 - diff)
			ans.push_back(i + 1);
		
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}
