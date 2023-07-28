#include <bits/stdc++.h>
#define x real()
#define y imag()

using namespace std;
typedef long long ll;
typedef complex<ll> P;

bool cmp(P a, P b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	int n;
	cin >> n;
	vector<P> arr(n);
	for (int i = 0; i < n; i++){
		ll xin, yin;
		cin >> xin >> yin;
		arr[i] = {xin, yin};
	}
	sort(arr.begin(), arr.end(), cmp);
	P ans[n * 2];
	int sz = 2;
	ans[0] = arr[0];
	ans[1] = arr[1];
	for (int i = 2; i < n; i++){
		while (sz > 1){
			P temp1 = ans[sz - 1], temp2 = ans[sz - 2];
			if ((conj(temp1 - temp2) * (arr[i] - temp1)).y <= 0)
				break;
			sz--;	
		}
		ans[sz++] = arr[i];
	}
	for (int i = n - 2; i >= 0; i--){
		while (sz > 1){
			P temp1 = ans[sz - 1], temp2 = ans[sz - 2];
			if ((conj(temp1 - temp2) * (arr[i] - temp1)).y <= 0)
				break;
			sz--;	
		}
		ans[sz++] = arr[i];
	}
	sz--;
	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i].x << " " << ans[i].y << "\n";
	return 0;
}
