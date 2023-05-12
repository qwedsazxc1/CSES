#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

bool check(vector<long long> &arr, int c, long long guess){
	long long bucket = INF;
	for (int i = 0; i < arr.size(); i++){
		if (arr[i] > guess)
			return false;
		if (bucket + arr[i] > guess)
			c--, bucket = 0;
		bucket += arr[i];
	}
	return c >= 0;
}

int main(){
	int n, c;
	cin >> n >> c;
	vector<long long> arr(n);
	long long sum = 0;
	for (auto &x: arr){
		cin >> x;
		sum += x;
	}
	long long l = 1, r = sum, ans = 0;
	while (l <= r){
		long long mid = (r - l) / 2 + l;
		if (check(arr, c, mid)){
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans << "\n";
}
