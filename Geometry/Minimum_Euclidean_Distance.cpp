#include <bits/stdc++.h>
#define x real()
#define y imag()
#define INF 0x7f3f3f3f3f3f3f3f
using namespace std;
typedef complex<long long> P;
typedef long long ll;

bool cmp(P a, P b){
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

struct mcmp{
	bool operator()(P a, P b) const {
		if (a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	P arr[n];
	for (int i = 0; i < n; i++){
		ll real, imag;
		cin >> real >> imag;
		arr[i] = {real, imag};
	}
	sort(arr, arr + n, cmp);
	set<P, mcmp> s;
	s.insert(arr[0]);
	ll d = INF;
	int l = 0;
	for (int i = 1; i < n; i++){
		P cur = arr[i];
		while (l < i){
			if (d >= (cur.x - arr[l].x) * (cur.x - arr[l].x)) break;
			s.erase({arr[l++]});
		}

		auto from = s.lower_bound({-INF, cur.y - sqrt(d)}), to = s.upper_bound({INF, cur.y + sqrt(d)});
		for (; from != to; from++){
			ll tempx = from->x - cur.x;
			tempx *= tempx;
			ll tempy = from->y - cur.y;
			tempy *= tempy;
			d = min(d, tempy + tempx);
		}
		s.insert(cur);
	}
	cout << d << "\n";
}
