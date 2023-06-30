#include <bits/stdc++.h>
#define x real()
#define y imag()
using namespace std;

typedef long long ll;
typedef complex<ll> P;
random_device seed;
mt19937 gen(seed());

bool isboundary(P l1, P l2, P p){
	if (p == l1 || p == l2)
		return true;
	ll cross = (((p - l1) * conj(p - l2)).y);
	if (l1.x > l2.x || (l1.x == l2.x && l1.y > l2.y)){
		P temp = l2;
		l2 = l1;
		l1 = temp;
	}
	return cross == 0 && l1.x <= p.x && l2.x >= p.x && l1.y <= p.y && l2.y >= p.y;
}

bool intersect(P p1, P p2, P p3, P p4){
	ll p1_locate = ((p1 - p3) * conj(p1 - p4)).y;
	ll p2_locate = ((p2 - p3) * conj(p2 - p4)).y;
	ll p3_locate = ((p3 - p1) * conj(p3 - p2)).y;
	ll p4_locate = ((p4 - p1) * conj(p4 - p2)).y;
	
	ll res1 = p1_locate * (p2_locate <= 0 ? (p2_locate ? -1 : 0) : 1);
	ll res2 = p3_locate * (p4_locate <= 0 ? (p4_locate ? -1 : 0) : 1);
	return res1 <= 0 && res2 <= 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	P arr[n];
	for (int i = 0; i < n; i++){
		ll real, imag;
		cin >> real >> imag;
		arr[i] = {real, imag};
	}
	while (m--){
		ll inputx, inputy;
		cin >> inputx >> inputy;
		P input = {inputx, inputy};
		bool bound = false;
		for (int i = 0; i < n; i++)
			if (bound = isboundary(arr[i], arr[(i + 1) % n], input))
				break;
		if (bound){
			cout << "BOUNDARY\n";
			continue;
		}
		ll targetx = gen() % (ll)1e9, targety = gen() % 100 + (ll)1e9 + 5;
		P target = {targetx, targety};
		ll intersect_count = 0;
		for (int i = 0; i < n; i++)
			if (intersect(input, target, arr[i], arr[(i + 1) % n]))
				intersect_count++;
		if (intersect_count & 1)
			cout << "INSIDE\n";
		else
			cout << "OUTSIDE\n";
	}
	return 0;
}
