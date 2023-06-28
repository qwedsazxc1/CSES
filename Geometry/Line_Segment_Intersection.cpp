#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef complex<long long> P;

bool cmp(P a, P b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

long long locate(P p1, P p2, P p3){
	P l1 = p3 - p1, l2 = p3 - p2;
	long long temp = (l1 * conj(l2)).y;
	if (temp < 0)
		return -1;
	if (temp == 0)
		return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		P p1, p2, p3, p4;
		for (int i = 0; i < 4; i++){
			long long int real, imag;
			cin >> real >> imag;
			if (i == 0)
				p1 = {real, imag};
			if (i == 1)
				p2 = {real, imag};
			if (i == 2)
				p3 = {real, imag};
			if (i == 3)
				p4 = {real, imag};
		}
		// if there are two point is same
		if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4){
			cout << "YES\n";
			continue;
		}

		P l1 = p2 - p1, l2 = p4 - p3, l3 = p3 - p2;
		// if all four points is on same line
		if ((l1 * conj(l2)).y == 0 && (l1 * conj(l3)).y == 0){
			P arr[4] = {p1, p2, p3, p4};
			sort(arr, arr + 4, cmp);
			if (arr[0] == p1 && arr[1] == p2){cout << "NO\n"; continue;}
			if (arr[1] == p1 && arr[0] == p2){cout << "NO\n"; continue;}
			if (arr[2] == p1 && arr[3] == p2){cout << "NO\n"; continue;}
			if (arr[3] == p1 && arr[2] == p2){cout << "NO\n"; continue;}
			cout << "YES\n";
			continue;
		}

		// if both point is on the different side
		if (locate(p1, p2, p3) * locate(p1, p2, p4) <= 0 && locate(p3, p4, p1) * locate(p3, p4, p2) <= 0){
			cout << "YES\n";
			continue;
		}
		
		cout << "NO\n";
	}
	return 0;
}
