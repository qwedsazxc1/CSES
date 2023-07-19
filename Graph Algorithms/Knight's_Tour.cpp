#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y;
	cin >> y >> x;
	x--; y--;
	vector<vector<int>> board(8, vector<int> (8, 0)), order(8, vector<int> (8, 0));
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (i > 0 && j < 6)
				board[i][j]++;
			if (i > 0 && j > 1)
				board[i][j]++;
			if (i > 1 && j > 0)
				board[i][j]++;
			if (i > 1 && j < 7)
				board[i][j]++;
			if (i < 6 && j > 0)
				board[i][j]++;
			if (i < 6 && j < 7)
				board[i][j]++;
			if (i < 7 && j > 1)
				board[i][j]++;
			if (i < 7 && j < 6)
				board[i][j]++;
		}
	}

	int cur_x = x, cur_y = y, count = 1;
	while (board[cur_x][cur_y] >= 0){
		board[cur_x][cur_y] = -1;
		order[cur_x][cur_y] = count++;
		int temp_x = -1, temp_y = -1, choose = 9;
		for (int i = 1; i <= 2; i++){
			for (int j = 1; j >= -1; j -= 2){
				for (int k = 1; k >= -1; k -= 2){
					int t = 1;
					if (i == 1)
						t = 2;
					if (cur_x + i * k * j < 8 && cur_x + i * k * j >= 0 && cur_y + t * k < 8 && cur_y + t * k >= 0){
						int new_x = cur_x + i * k * j, new_y = cur_y + t * k;
						board[new_x][new_y] -= 1;
						if (board[new_x][new_y] >= 0 && board[new_x][new_y] <= choose){
							choose = board[new_x][new_y];
							temp_x = new_x;
							temp_y = new_y;
						}
					}
				}
			}
		}
		
		cur_x = temp_x;
		cur_y = temp_y;
		if (temp_x == -1)
			break;
	}
	if (count != 65){
		board.assign(8, vector<int> (8, 0));
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (i > 0 && j < 6)
					board[i][j]++;
				if (i > 0 && j > 1)
					board[i][j]++;
				if (i > 1 && j > 0)
					board[i][j]++;
				if (i > 1 && j < 7)
					board[i][j]++;
				if (i < 6 && j > 0)
					board[i][j]++;
				if (i < 6 && j < 7)
					board[i][j]++;
				if (i < 7 && j > 1)
					board[i][j]++;
				if (i < 7 && j < 6)
					board[i][j]++;
			}
		}

		int cur_x = x, cur_y = y, count = 1;
		while (board[cur_x][cur_y] >= 0){
			board[cur_x][cur_y] = -1;
			order[cur_x][cur_y] = count++;
			int temp_x = -1, temp_y = -1, choose = 9;
			for (int i = 1; i <= 2; i++){
				for (int j = 1; j >= -1; j -= 2){
					for (int k = 1; k >= -1; k -= 2){
						int t = 1;
						if (i == 1)
							t = 2;
						if (cur_x + i * k * j < 8 && cur_x + i * k * j >= 0 && cur_y + t * k < 8 && cur_y + t * k >= 0){
							int new_x = cur_x + i * k * j, new_y = cur_y + t * k;
							board[new_x][new_y] -= 1;
							if (board[new_x][new_y] >= 0 && board[new_x][new_y] < choose){
								choose = board[new_x][new_y];
								temp_x = new_x;
								temp_y = new_y;
							}
						}
					}
				}
			}
		
			cur_x = temp_x;
			cur_y = temp_y;
			if (temp_x == -1)
				break;
		}
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			cout << order[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
