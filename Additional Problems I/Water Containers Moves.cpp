#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define FILL 0
#define EMPTY 1
#define MOVE 2

using namespace std;
using ll = long long;

int main(){
	int a, b, x;
	cin >> a >> b >> x;
	auto gcd = [&](auto &self, int a, int b) -> int {
		if (b == 0)
			return a;
		return self(self, b, a % b);
	};
	int g = gcd(gcd, a, b);
	if (x > a || x % g != 0){
		cout << "-1\n";
		return 0;
	}
	int ans = 0;
	int flag = 0;
	vector<int> temp1, temp2;
	int res = 0;
	int cura = 0, curb = 0;
	while (cura != x){
		if (cura == 0){
			cura = a;
			res += a;
			temp1.push_back(FILL);
		}
		if (cura == x)
			break;
		int temp = min(b - curb, cura);
		cura -= temp;
		res += temp;
		curb += temp;
		temp1.push_back(MOVE);
		if (cura == x)
			break;
		if (curb == b){
			temp1.push_back(EMPTY);
			curb = 0;
			res += b;
		}
	}
	ans = res;
	vector<int> moves = temp1;
	res = 0;
	cura = 0, curb = 0;
	while (cura != x){
		if (curb == 0){
			temp2.push_back(FILL);
			curb = b;
			res += b;
		}
		int temp = min(a - cura, curb);
		cura += temp;
		curb -= temp;
		res += temp;
		temp2.push_back(MOVE);
		if (cura == x)
			break;
		if (cura == a){
			temp2.push_back(EMPTY);
			cura = 0;
			res += a;
		}
	}
	if (res < ans){
		flag = 1;
		ans = res;
		moves = temp2;
	}
	cout << moves.size() << " " << ans << "\n";
	for (auto x: moves){
		if (x == FILL)
			cout << "FILL " << "AB"[flag] << "\n";
		else if (x == EMPTY)
			cout << "EMPTY " << "BA"[flag] << "\n";
		else
			cout << "MOVE " << "AB"[flag] << " " << "BA"[flag] << "\n";
	}
}
