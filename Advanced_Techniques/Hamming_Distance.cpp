#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	bitset<30> arr[n];
	for (int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		for (int j = 0; j < k; j++)
			arr[i][j] = temp[j] - '0';
	}
	int ans = INF;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++){
			ans = min(ans, (int)((arr[i] ^ arr[j]).count()));
		}
	cout << ans << "\n";
	return 0;
}
