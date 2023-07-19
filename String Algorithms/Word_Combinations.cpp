#include <bits/stdc++.h>
#define MOD (long long)1e9 + 7
using namespace std;
typedef pair<int, int> pii;

int trie[(long long)1e6 + 5][26];
bool check[(long long)1e6 + 5];

int main(){
	string str;
	cin >> str;
	int k;
	cin >> k;
	int node_amount = 1;
	for (int i = 0; i < k; i++){
		string temp;
		cin >> temp;
		int cur = 0;
		for (auto c: temp){
			c -= 'a';
			if (trie[cur][c] == 0)
				trie[cur][c] = node_amount++;
			cur = trie[cur][c];
		}
		check[cur] = true;
	}
	queue<pair<int, int>> q;
	long long dp[str.size() + 1] = {};
	dp[0] = 1;
	for (int i = 0; i < str.size(); i++){
		char c = str[i] - 'a';
		q.push({0, 0});
		int qsize = q.size();
		for (int j = 0; j < qsize; j++){
			pii node = q.front();
			q.pop();
			if (trie[node.first][c] == 0)
				continue;
			int cur = trie[node.first][c];
			
			// if there is a word
			if (check[cur]){
				dp[i + 1] += dp[i - node.second];
				dp[i + 1] %= MOD;
			}

			q.push({cur, node.second + 1});
		}
	}
	cout << dp[str.size()] << "\n";
	return 0;
}
