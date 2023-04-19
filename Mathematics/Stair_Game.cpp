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
			if (i & 1)
				res ^= input;
		}
		if (res == 0)
			cout << "second\n";
		else
			cout << "first\n";
	}
	return 0;
}
