#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef long long ll;
typedef complex<ll> P;

ll gcd(ll a, ll b){
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){
	int n;
	cin >> n;
	P arr[n];
	for (int i = 0; i < n; i++){
		ll real, imag;
		cin >> real >> imag;
		arr[i] = {real, imag};
	}

	ll boundary = 0, area = 0;
	for (int i = 0; i < n; i++){
		P line = arr[(i + 1) % n] - arr[i];
		area += arr[i].x * arr[(i + 1) % n].y - arr[i].y * arr[(i + 1) % n].x;
		boundary += gcd((line.x < 0 ? -line.x : line.x), (line.y < 0 ? -line.y : line.y));
	}
	if (area < 0)
		area = -area;
	area += 2;
	ll in = (area - boundary) / 2;
	cout << in << " " << boundary << "\n";
	return 0;
}
