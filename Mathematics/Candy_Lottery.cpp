#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	double ans = 0;
	for (int i = 1; i <= k; i++){
		double include = 1, exclude = 1;
		for (int j = 0; j < n; j++){
			include *= (double)i / k;
			exclude *= (double)(i - 1) / k;
		}
		ans += i * (include - exclude);
	}
	ans *= 1e6;
	ans = round(ans);
	ans /= 1e6;
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
