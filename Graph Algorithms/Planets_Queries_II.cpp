#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> succ;

void build(){
	for (int i = 1; i < 20; i++)
		for (int j = 0; j < succ.size(); j++)
			succ[j][i] = succ[succ[j][i - 1]][i - 1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	succ.assign(n, vector<int> (20));
	for (int i = 0; i < n; i++){
		cin >> succ[i][0];
		succ[i][0]--;
	}
	build();

	int compoment_amount = 0;
	vector<int> compoment_id(n, -1), locate(n), cycle_size(n, -1);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++){
		if (visited[i])
			continue;
		int cur = i;
		while (!visited[cur]){
			visited[cur] = true;
			cur = succ[cur][0];
		}
		if (compoment_id[cur] != -1){
			int count = 0;
			int temp = i;
			while (temp != cur){
				count++;
				compoment_id[temp] = compoment_id[cur];
				temp = succ[temp][0];
			}
			if (locate[cur] > 0)
				count += locate[cur];
			temp = i;
			while (temp != cur){
				locate[temp] = count--;
				temp = succ[temp][0];
			}
		}
		else{
			int id = compoment_amount++;
			int temp = i, count = 0;
			while (temp != cur){
				count++;
				compoment_id[temp] = id;
				temp = succ[temp][0];
			}
			temp = i;
			while (temp != cur){
				locate[temp] = count--;
				temp = succ[temp][0];
			}
			int node_locate = -1;
			locate[cur] = 0;
			compoment_id[cur] = id;
			temp = succ[cur][0];
			while (temp != cur){
				compoment_id[temp] = id;
				locate[temp] = node_locate--;
				temp = succ[temp][0];
			}
			node_locate = -node_locate;
			temp = succ[cur][0];
			cycle_size[cur] = node_locate;
			while (temp != cur){
				cycle_size[temp] = node_locate;
				temp = succ[temp][0];
			}
		}
	}

	while (q--){
		int a, b;
		cin >> a >> b;
		a--; b--;

		// not in same compoment
		if (compoment_id[a] != compoment_id[b]){
			cout << "-1\n";
			continue;
		}

		// destination on chain
		if (locate[b] > 0){
			if (locate[a] < locate[b]){
				cout << "-1\n";
				continue;
			}
			int step = locate[a] - locate[b];
			for (int i = 0; i < 20; i++){
				if (step & (1 << i))
					 a = succ[a][i];
			}
			if (a == b)
				cout << step << "\n";
			else
				cout << "-1\n"; 
			continue;
		}

		int step = 0;
		// source on chain
		if (locate[a] > 0){
			step = locate[a];
			for (int i = 0; i < 20; i++)
				if (step & (1 << i))
					a = succ[a][i];
		}
	
		// source on cycle

		// for debug
		if (cycle_size[a] <= 0 || cycle_size[a] != cycle_size[b]){
			cout << "a: " << a << " b: " << b << "\n";
			cout << "cycle less than 0 or not equal size\n";
			continue;
		}

		if (locate[a] < locate[b]){
			step += cycle_size[a] - (locate[b] - locate[a]);
		}
		else{
			step += locate[a] - locate[b];
		}
		cout << step << "\n";
	}
	return 0;
}
