#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k){
	if (n & 1){
		if ((n + 1) / 2 == k)
			return 1;
		if (n / 2 >= k)
			return k * 2;
		return 2 * josephus(n / 2, k - (n + 1) / 2) + 1;
	}
	else{
		if (n / 2 >= k)
			return k * 2;
		return 2 * josephus(n / 2, k - n / 2) - 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--){
		int n, k;
		cin >> n >> k;
		cout << josephus(n, k) << "\n";
	}
	return 0;
}
