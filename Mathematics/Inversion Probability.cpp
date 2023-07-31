#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

int main(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;

	ld ans = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			ll temp;
			if (arr[i] > arr[j]){
				temp = (arr[j] * (arr[j] - 1)) / 2;
				temp += (arr[i] - arr[j]) * arr[j];
			}
			else
				temp = (arr[i] * (arr[i] - 1)) / 2;
			ans += (ld)temp / (ld)(arr[i] * arr[j]);
		}
	}
	cerr << fixed << setprecision(20) << ans << "\n";
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
