#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	long double ans = 0;
	for (int i = 1; i <= k; i++){
		long double include = 1, exclude = 1;
		for (int j = 0; j < n; j++){
			include *= (long double)i;
			exclude *= (long double)(i - 1);
		}
		ans += i * (include - exclude);
	}
	for (int i = 0; i < n; i++)
		ans /= k;
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
