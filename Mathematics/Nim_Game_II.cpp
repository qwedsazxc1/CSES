#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int res = 0;
		for (int i = 0; i < n; i++){
			int input;
			cin >> input;
			res ^= input;
		}
		res &= 3;
		if (res)
			cout << "first\n";
		else
			cout << "second\n";
	}
	return 0;
}
