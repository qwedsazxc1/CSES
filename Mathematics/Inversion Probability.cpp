#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;

struct number{
	vector<short> num;
	number(ll a = 0){
		if (a == 0){
			num.push_back(0);
		}
		else{
			while (a){
				num.push_back(a % 10);
				a /= 10;
			}
		}
	}
	number operator+(number &b){
		number res;
		res.num.push_back(0);
		int car = 0;
		for (int i = 0; i < max(num.size(), b.num.size()); i++){
			int l, r;
			if (i >= (int)num.size()){
				l = 0;
			}
			else
				l = num[i];
			if (i >= b.num.size())
				r = 0;
			else
				r = b.num[i];
			int temp = car + l + r;
			res.num[i] = temp % 10;
			car = temp / 10;
			res.num.push_back(car);
		}
		if (res.num.back() == 0)
			res.num.pop_back();
		return res;
	}
	number operator*(number &b){
		
	}
};

struct frac{
	number num, den;
	frac(ll a, ll b) : num(a), den(a){}
	double round(int dig){
		
	}
	frac operator+(frac &b){
		frac res(num * b.den + b.num * den, den * b.den);
		return res;
	}
};


int main(){
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;

	ld ans = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			ll temp;
			if (arr[i] > arr[j]){
				temp = (arr[j] * (arr[j] - 1)) / 2;
				temp += (arr[i] - arr[j]) * arr[j];
			}
			else
				temp = (arr[i] * (arr[i] - 1)) / 2;
			ans += (ld)temp / (ld)(arr[i] * arr[j]);
		}
	}
	cerr << fixed << setprecision(20) << ans << "\n";
	cout << fixed << setprecision(6) << ans << "\n";
	return 0;
}
