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
	ans *= 1e6;
	long long temp = ans;
	ans -= temp;
	if (ans >= 0.5 - 1e-12 && ans <= 0.5 + 1e-12){
		if (temp & 1){
			ans += 0.5;
		}
		else
			ans -= 0.5;
	}
	ans += temp;
	ans /= 1e6;
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
