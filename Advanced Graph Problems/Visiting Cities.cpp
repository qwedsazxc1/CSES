#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll fast_pow(ll base, ll power){
	ll res = 1;
	while (power){
		if (power & 1){
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		power >>= 1;
	}
	return res;
}

ll mod_inverse(ll x){
	return fast_pow(x, MOD - 2);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> graph(n), rev(n);
	for (int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v, w});
		rev[v].push_back({u, w});
	}
	vector<ll> dist(n, INF);
	vector<ll> ord;
	ord.reserve(n);
	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
	pq.push({0, {0, 0}});
	while (!pq.empty()){
		auto t = pq.top();
		pq.pop();
		int cur = t.second.first, prev = t.second.second;
		ll w = t.first;
		if (dist[cur] != INF)
			continue;
		ord.push_back(cur);
		dist[cur] = w;
		for (auto next: graph[cur]){
			pq.push({w + next.second, {next.first, cur}});
		}
	}
	vector<ll> dp(n);
	dp[n - 1] = 1;
	for (int i = n - 1; i >= 0; i--){
		int cur = ord[i];
		int cnt = 0;
		for (auto [prev, w]: rev[cur]){
			if (dist[prev] + w == dist[cur]){
				cnt++;
			}
		}
		for (auto [prev, w]: rev[cur]){
			if (dist[prev] + w == dist[cur]){
				dp[prev] = (dp[prev] + dp[cur] * mod_inverse(cnt)) % MOD;
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (dp[i] == 1)
			ans.push_back(i + 1);
		
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}
