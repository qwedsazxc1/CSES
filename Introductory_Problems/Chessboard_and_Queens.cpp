#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(8, vector<int>(8));

long long ans = 0;

void dfs(int i, int j, int count){
	if (i >= 8 || i < 0 || j >= 8 || j < 0 || board[i][j])
		return;
	if (count == 8){
		ans++;
		return;
	}
	for (int k = 0; k < 8; k++){
		if (board[i][k] == 0)
			board[i][k] = count;
		if (board[k][j] == 0)
			board[k][j] = count;
		int temp = k - i + j;
		if (temp >= 0 && temp < 8 && board[k][temp] == 0){
			board[k][temp] = count;
		}
		temp = i + j - k;
		if (temp >= 0 && temp < 8 && board[temp][k] == 0)
			board[temp][k] = count;
	}
	for (int k = 0; k < 8; k++){
		dfs(i + 1, k, count + 1);
	}
	for (int k = 0; k < 8; k++){
		if (board[i][k] == count)
			board[i][k] = 0;
		if (board[k][j] == count)
			board[k][j] = 0;
		int temp = k - i + j;
		if (temp >= 0 && temp < 8 && board[k][temp] == count){
			board[k][temp] = 0;
		}
		temp = i + j - k;
		if (temp >= 0 && temp < 8 && board[temp][k] == count)
			board[temp][k] = 0;
	}
}

int main(){

	for (int  i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			char input;
			cin >> input;
			if (input == '*')
				board[i][j] = 80;
			else
				board[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++)
		dfs(0, i, 1);
	cout << ans << "\n";
}
