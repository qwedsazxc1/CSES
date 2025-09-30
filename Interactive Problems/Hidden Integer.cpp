#include <bits/stdc++.h>

using namespace std;

int main(){
	int l = 1, r = 1e9;
	int ans = 0;
	while (l <= r){
		int mid = (r - l) / 2 + l;
		cout << "? " << mid << endl;
		string res;
		cin >> res;
		if (res == "YES"){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	cout << "! " << ans << endl;
}
