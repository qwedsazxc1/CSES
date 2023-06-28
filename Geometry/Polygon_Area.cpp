#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef complex<long long> P;

int main(){
	int n;
	cin >> n;
	P arr[n];
	for (int i = 0; i < n; i++){
		long long real, image;
		cin >> real >> image;
		arr[i] = {real, image};
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; i++){
		ans += arr[i].x * arr[i + 1].y - arr[i].y * arr[i + 1].x;
	}
	ans += arr[n - 1].x * arr[0].y - arr[n - 1].y * arr[0].x;
	if (ans < 0)
		ans = -ans;
	cout << ans << "\n";
	return 0;
}
