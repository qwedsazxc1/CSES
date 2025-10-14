#include <bits/stdc++.h>

using namespace std;

int main(){
	string in;
	in.resize(9);
	for (int i = 0; i < 9; i++){
		cin >> in[i];
	}
	
	unordered_set<string> s;
	queue<pair<string, int>> q;
	q.push({in, 0});
	in = "123456789";
	while (!q.empty()){
		auto f = q.front();
	   	q.pop();
		if (f.first == in){
			cout << f.second << "\n";
			break;
		}	
		int w = f.second;
		auto cur = f.first;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++){
				if (i != 2){
					swap(cur[i * 3 + j], cur[(i + 1) * 3 + j]);
					if (s.find(cur) == s.end()){
						q.push({cur, w + 1});
						s.insert(cur);
					}
					swap(cur[i * 3 + j], cur[(i + 1) * 3 + j]);
				}
				if (j != 2){
					swap(cur[i * 3 + j], cur[i * 3 + j + 1]);
					if (s.find(cur) == s.end()){
						q.push({cur, w + 1});
						s.insert(cur);
					}
					swap(cur[i * 3 + j], cur[i * 3 + j + 1]);
				}
			}
	}
	return 0;
}
