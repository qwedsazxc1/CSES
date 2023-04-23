#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<double> dp(n * 6 + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = i * 6; j >= i; j--){
			for (int k = 1; k <= 6; k++)
				dp[j + k] += dp[j] / 6;
			dp[j] = 0;
		}
	}
	double sum = 0;
	for (int i = a; i <= b; i++)
		sum += dp[i];
	printf("%.6f\n", sum);
	return 0;
}
