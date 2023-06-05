#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef long long ll;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> prefix(n + 1, 0);
	for (int i = 0; i < n; i++){
		ll input;
		cin >> input;
		prefix[i + 1] = input + prefix[i];
	}
	multiset<ll> s;
	ll ans = -INF;
	for (int i = a; i <= n; i++){
		if (i > b){
			s.erase(s.find(prefix[i - b - 1]));
		}
		s.insert(prefix[i - a]);
		ans = max(ans, prefix[i] - *s.begin());
	}
	cout << ans << "\n";
	return 0;
}
