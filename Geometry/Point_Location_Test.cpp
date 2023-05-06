#include <bits/stdc++.h>

#define x real()
#define y imag()
using namespace std;

typedef complex<long long> p;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		p p1, p2, p3;
		for (int i = 0; i < 3; i++){
			long long inx, iny;
			cin >> inx >> iny;
			if (i == 0)
				p1 = {inx, iny};
			if (i == 1)
				p2 = {inx, iny};
			if (i == 2)
				p3 = {inx, iny};
		}
		long long res = (conj((p3 - p1)) * (p3 - p2)).y;
		if (res > 0){
			cout << "LEFT\n";
		}
		else if (res == 0){
			cout << "TOUCH\n";
		}
		else{
			cout << "RIGHT\n";
		}
	}
	return 0;
}
