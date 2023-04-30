#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bit;

void update(int kx, int ky, int x, int maxn){
	for (int i = kx; i <= maxn; i += i & -i)
		for (int j = ky; j <= maxn; j += j & -j)
			bit[i][j] += x;
}

int query(int qx, int qy){
	int res = 0;
	for (int i = qx; i > 0; i -= i & -i)
		for (int j = qy; j > 0; j -= j & -j)
			res += bit[i][j];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> board(n, vector<int>(n, 0));
	bit.assign(n + 1, vector<int> (n + 1, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			char input;
			cin >> input;
			if (input == '*'){
				board[i][j] = 1;
				update(i + 1, j + 1, 1, n);
			}
		}
	while (q--){
		int op;
		cin >> op;
		if (op == 1){
			int kx, ky;
			cin >> kx >> ky;
			if (board[kx - 1][ky - 1] == 0){
				board[kx - 1][ky - 1] = 1;
				update(kx, ky, 1, n);
			}
			else{
				board[kx - 1][ky - 1] = 0;
				update(kx, ky, -1, n);
			}
		}
		else{
			int qxl, qyl, qxr, qyr;
			cin >> qxl >> qyl >> qxr >> qyr;
			cout << query(qxr, qyr) + query(qxl - 1, qyl - 1) - query(qxr, qyl - 1) - query(qxl - 1, qyr) << "\n";
		}
	}
	return 0;
}
