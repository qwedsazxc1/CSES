#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> arr(n + 1), idx(n + 2);
	arr[0] = idx[0] = 0;
	idx[n + 1] = n + 1;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		idx[x] = i;
		arr[i] = x;
	}
	int c = 0, bound = INF;
	for (int i = 1; i <= n; i++){
		if (bound > idx[i]){
			c++;
		}
		bound = idx[i];
	}
	while (q--){
		int a, b;
		cin >> a >> b;
		int va = arr[a], vb = arr[b];
		swap(arr[a], arr[b]);
		if (idx[va - 1] > b) c++;
		if (idx[va - 1] > a) c--;
		if (idx[va + 1] <= b) c++;
		if (idx[va + 1] < a) c--;
		if (idx[vb - 1] > a) c++;
		if (idx[vb - 1] > b) c--;
		if (idx[vb + 1] <= a) c++;
		if (idx[vb + 1] < b) c--;
		idx[va] = b;
		idx[vb] = a;
		cout << c << "\n";
	}
	return 0;
}
