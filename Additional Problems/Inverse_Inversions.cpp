#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;
	int count = 1, upper = n;
	for (int i = n - 1; i >= 0; i--)
		if (i <= k){
			k -= i;
			cout << upper-- << " ";
		}
		else{
			cout << count++ << " ";
		}
	cout << "\n";
	return 0;
}
