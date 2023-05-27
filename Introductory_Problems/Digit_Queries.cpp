#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll power(ll base, ll exp){
	ll res = 1;
	while (exp){
		if (exp & 1)
			res *= base;
		base *= base;
		exp >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<ll> amount(18, 0), dig(18, 0);
	dig[1] = amount[1] = 9;
	for (int i = 2; i < 18; i++)
		amount[i] = amount[i - 1] * 10;
	for (ll i = 2; i < 18; i++){
		dig[i] = dig[i - 1] + amount[i] * i;
	}
	int q;
	cin >> q;
	while (q--){
		ll k;
		cin >> k;
		ll count = 1;
		for (int i = 17; i >= 0; i--)
			if (k > dig[i]){
				count = i + 1;
				break;
			}
		ll rec = count - ((k - dig[count - 1] - 1) % count) - 1, cnt = (k - dig[count - 1]) / count;
	#ifdef DEBUG
		cout << rec << " " << cnt << "\n";
	#endif
		cnt--;
		ll locate = power(10, rec);
		ll temp = (k - 1 - dig[count - 1]) / count + power(10, count - 1);
	#ifdef DEBUG
		cout << locate << " " << temp << "\n";
	#endif
		temp = temp % (10 * locate);
		while (locate > 1){
			temp /= 10;
			locate /= 10;
		}
		cout << temp << "\n";
	}
	return 0;
}
