#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	bitset<3000> arr[n];
	for (int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)
			arr[i][j] = temp[j] - '0';
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++){
			long long res = (arr[i] & arr[j]).count();
			ans += res * (res - 1) / 2; 
		}
	cout << ans << "\n";
	return 0;
}
