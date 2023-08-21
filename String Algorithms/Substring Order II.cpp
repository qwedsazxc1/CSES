#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

int node_amount = 1, last_state = 0;
int automaton[maxn][26];
int li[maxn], length[maxn];
ll dp[maxn], sz[maxn];
bool vis[maxn], accepted[maxn];

void SA(string &str){
	int n = (int)str.size();
	li[0] = -1;
	for (int i = 0; i < n; i++){
		int c = str[i] - 'a';
		int y = node_amount++, x = last_state, s = -1;
		last_state = y;
		automaton[x][c] = y;
		li[y] = 0;
		length[y] = length[x] + 1;
		while (li[x] != -1){
			x = li[x];
			if (automaton[x][c] != 0){
				s = x;
				break;
			}
			automaton[x][c] = y;
		}
		if (s == -1)
			continue;
		int u = automaton[s][c];
		if (length[s] + 1 == length[u]){
			li[y] = u;
			continue;
		}
		int z = node_amount++;
		for (int i = 0; i < 26; i++)
			automaton[z][i] = automaton[u][i];
		li[z] = li[u];
		length[z] = length[s] + 1;

		for (int i = s; i != -1 && automaton[i][c] == u; i = li[i])
			automaton[i][c] = z;
		li[y] = li[u] = z;
	}
	int temp = last_state;
	while (li[temp] != -1){
		dp[temp]++;
		accepted[temp] = true;
		temp = li[temp];
	}
}

void DFS(int cur){
	sz[cur] = (ll)accepted[cur];
	vis[cur] = true;
	for (int i = 0; i < 26; i++){
		int next = automaton[cur][i];
		if (next == 0)
			continue;
		if (!vis[next])
			DFS(next);
		dp[cur] += dp[next];	
		sz[cur] += sz[next];	
	}
}

int main(){
	string str;
	ll k;
	cin >> str >> k;
	SA(str);
	DFS(0);
	memset(vis, 0, sizeof(vis));
	DFS(0);
	int cur = 0;
	string ans;
	while (k > 0){
		for (int i = 0; i < 26; i++){
			if (automaton[cur][i] == 0)
				continue;
			int next = automaton[cur][i];
			if (k > dp[next])
				k -= dp[next];
			else{
				ans.push_back(i + 'a');
				cur = next;
				k -= sz[next];
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
