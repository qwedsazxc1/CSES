#include <bits/stdc++.h>

using namespace std;

int count2_factor(int x){
	int res = 0;
	while (x){
		x >>= 1;
		res += x;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	int n2factors = count2_factor(n - 1);
	int ans = 0;
	for (int i = 0; i < n; i++){
		int input;
		cin >> input;
		if (n2factors == count2_factor(i) + count2_factor(n - 1 - i)) ans ^= input;
	}
	cout << ans << "\n";
	return 0;
}
