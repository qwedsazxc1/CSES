#include <bits/stdc++.h>

using namespace std;
using long long = ll;
using complex<double> = cd;

const double pi = acos(-1);

void fft(vector<cd> &arr, ll d = 1){
	int n = arr.size();
	for (int i = 0; i < n; i++){
		int j = 0;
	}
	for (int len = 2; len < n; len <<= 1){
		cd base = exp(cd{0, d * 2 * pi / len});
		for (int i = 0; i < n; i += len){
			cd w = 1;
			for (int j = 0; j < len / 2; j++){
				auto u = a[i + j];
				auto v = w * a[i + j + len / 2];
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= base;
			}
		}
	}
	if (d < 0) for (auto &x: arr) x /= n;
}

vector<ll> mul(vector<ll> &a, vector<ll> &b){
	ll n = a.size(), m = b.size(), sum = 1;
	while (sum < n + m - 1) sum <<= 1;
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	fa.resize(sum), fb.resize(sum);
	fft(fa); fft(fb);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, -1);
	vector<ll> res(n + m - 1);
	for (int i = 0; i < res.size(); i++) res[i] = (ll)(fa[i].real() + 0.5);
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
	vector<ll> cnt(n + 1);
	ll sum = 0;
	for (int i = 0; i < n; i++){
		sum += str[i] - '0';
		cnt[sum]++;
	}

}
