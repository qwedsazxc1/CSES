#include <bits/stdc++.h>

using namespace std;

#define MAX ((long long)1e6 + 5)

int main(){
	int n;
	cin >> n;
	vector<int> cnt(MAX, 0);
	for (int i = 0; i < n; i++){
		int input;
		cin >> input;
		cnt[input]++;
	}
	for (int gcd = MAX; gcd > 0; gcd--){
		int count = 0;
		for (int i = gcd; i < MAX; i += gcd){
			count += cnt[i];
			if (count >= 2){
				cout << gcd << "\n";
				return 0;
			}
		}
	}
	return 0;
}
