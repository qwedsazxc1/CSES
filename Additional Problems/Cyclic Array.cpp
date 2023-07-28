#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxbit = 20;

ll succ[(int)2e5][maxbit], length[(int)2e5][maxbit];
bool check(int n, int mid){
	for (int i = 0; i < n; i++){
		ll cur = i, len = 0;
		for (int j = 0; j < maxbit; j++){
			if (mid & (1 << j)){
				len += length[cur][j];
				cur = succ[cur][j];
			}
		}
		if (len >= n)
			return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> arr(n);
	ll sum = 0;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum <= k){
		cout << "1\n";
		return 0;
	}

	sum = 0;
	for (int l = 0, r = 0; l < n; l++){
		while (sum + arr[r % n] <= k){
			sum += arr[r % n];
			r++;
		}
		succ[l][0] = r % n;
		length[l][0] = r - l;
		sum -= arr[l];
	}
	for (int i = 1; i < maxbit; i++){
		for (int j = 0; j < n; j++){
			succ[j][i] = succ[succ[j][i - 1]][i - 1];
			length[j][i] = length[j][i - 1] + length[succ[j][i - 1]][i - 1];
		}
	}

	int l = 2, r = n, ans = 2;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(n, mid)){
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans << "\n";
	return 0;
}
