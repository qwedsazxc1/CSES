#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n - 2);
	for (auto &x: arr)
		cin >> x;
	int cur = n, not_used = n - 1;
	vector<bool> used(n, false);
	used[n - 1] = true;
	for (int i = n - 3; i >= 0; i--){
		if (used[arr[i] - 1]){
			cout << cur << " " << not_used << "\n";
			used[not_used - 1] = true;
		}
		else{
			cout << cur << " " << arr[i] << "\n";
			used[arr[i] - 1] = true;
		}
		cur = arr[i];
		while (used[not_used - 1]) not_used--;
	}
	cout << cur << " " << not_used << "\n";
	return 0;
}
