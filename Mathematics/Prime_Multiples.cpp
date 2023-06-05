#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int number_of_digit(ll x){
	int res = 0;
	while (x / 10){
		x /= 10;
		res++;
	}
	return res;
}

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(k);
	vector<double> digit_amount(k);
	for (int i = 0; i < k; i++){
		cin >> arr[i];
		digit_amount[i] = log(arr[i]);
	}
	double n_digit_amount = log(n);
	n_digit_amount += 0.001;
	ll ans = 0;
	for (ll bit = 1; bit < (1 << k); bit++){
		ll count1 = 0;

		ll down = 1;
		double down_digit_amount = 0;
		for (long long i = 0; i < k; i++){
			if (bit & (1 << i)){
				count1++;
				down *= arr[i];
				down_digit_amount += digit_amount[i];
			}
		}
		if (down_digit_amount > n_digit_amount)
			continue;
		ans += (count1 & 1 ? (n / down) : (-1 * n / down));
	}
	cout << ans << "\n";
	return 0;
}
