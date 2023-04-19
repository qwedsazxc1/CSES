#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int flag = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			int input;
			cin >> input;
			flag |= input & 1;
		}
		cout << (flag ? "first\n" : "second\n");
	}
	return 0;
}
