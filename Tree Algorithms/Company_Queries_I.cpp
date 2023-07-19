#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n, q;
	cin >> n >> q;
	vector<vector<int>> parent(n + 1, vector<int>(20));
	parent[1][0] = -1;
	for (int i = 2; i <= n; i++)
		cin >> parent[i][0];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++){
			if (parent[j][i - 1] == -1)
				parent[j][i] = -1;
			else
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
			
		}
	while (q--){
		int node, k;
		cin >> node >> k;
		int i = 0;
		while (k){
			if (k & 1){
				node = parent[node][i];
			}
			if (node == -1)
				break;
			k >>= 1;
			i++;
		}
		cout << node << "\n";
	}
	return 0;
}
