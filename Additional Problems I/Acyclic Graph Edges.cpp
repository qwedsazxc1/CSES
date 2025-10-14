#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		cout << u << " " << v << "\n";
	}
	return 0;
}
