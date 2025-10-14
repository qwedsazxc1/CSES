#include <bits/stdc++.h>

using namespace std;

const int bit = 30;
const int N = 2e5 + 5;

int trie[N * bit][2] = {}, node_amount = 0;

void insert(int a){
	int temp = 1 << bit;
	int cur = 0;
	for (int i = bit; i >= 0; i--){
		if (temp & a){
			if (trie[cur][1] == 0)
				trie[cur][1] = ++node_amount;
			cur = trie[cur][1];
		}
		else{
			if (trie[cur][0] == 0)
				trie[cur][0] = ++node_amount;
			cur = trie[cur][0];
		}
		temp >>= 1;
	}
}

int query(int a){
	int res = 0, cur = 0, temp = 1 << bit;
	for (int i = bit; i >= 0; i--){
		if (a & temp){
			if (!trie[cur][0]){
				res |= temp;
				cur = trie[cur][1];
			}
			else
				cur = trie[cur][0];
		}
		else{
			if (trie[cur][1]){
				res |= temp;
				cur = trie[cur][1];
			}
			else
				cur = trie[cur][0];
		}
		temp >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int ans = 0, pre = 0;
	insert(pre);
	for (int i = 0; i < n; i++){
		int in;
		cin >> in;
		pre ^= in;
		insert(pre);
		ans = max(ans, pre ^ query(pre));
	}
	cout << ans << "\n";
}
