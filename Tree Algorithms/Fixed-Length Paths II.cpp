#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int n, l, r;
vector<ll> graph[maxn];
ll ans = 0;

ll prefix(deque<ll> &arr, int r){
	if (r < 0)
		return 0;
	if (r >= (int)arr.size() - 1)
		return arr[0];
	return arr[0] - arr[r + 1];
}

void cnt(deque<ll> &a, deque<ll> &b){
	if (a.size() < b.size())
		swap(a, b);
	for (int i = 0; i < (int)b.size() - 1; i++)
		b[i] -= b[i + 1];
	for (int i = 0; i < (int)b.size(); i++){
		if (i > r)
			break;
		ans += b[i] * (prefix(a, r - i) - prefix(a, l - i - 1));
	}
    for (int i = b.size() - 1; i > 0; i--)
		b[i - 1] += b[i];
	for (int i = 0; i < (int)b.size(); i++)
		a[i] += b[i];	
}

deque<ll> dfs(int cur, int prev){
	deque<ll> res{1};
	for (auto next: graph[cur]){
		if (next == prev)
			continue;
		auto temp = dfs(next, cur);
		temp.push_front(temp.front());
		cnt(res, temp);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}
