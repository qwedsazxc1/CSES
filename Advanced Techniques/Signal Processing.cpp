#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1);
typedef long long ll;
typedef complex<double> cd;

vector<cd> fft(vector<cd> a, int d = 1){
	int n = a.size();
	vector<cd> r(n);
	for (int k = 0; k < n; k++){
		int b = 0;
		for (int z = 1; z < n; z *= 2){
			b *= 2;
			if (k & z)
				b++;
		}
		r[b] = a[k];
	}
	for (int m = 2; m <= n; m *= 2){
		cd wm = exp(cd{0, pi * d * 2 / m});
		for (int k = 0; k < n; k += m){
			cd w = 1;
			for (int j = 0; j < m / 2; j++){
				cd u = r[k + j];
				cd t = w * r[k + j + m / 2];
				r[k + j] = u + t;
				r[k + j + m / 2] = u - t;
				w = w * wm;
			}
		}
	}
	if (d == -1)
		for (int i = 0; i < n; i++)
			r[i] /= n;
	return r;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<cd> arr1(n), arr2(m);
	for (int i = 0; i < n; i++){
		int v;
		cin >> v;
		arr1[i] = {(double)v, 0};
	}
	for (int i = 0; i < m; i++){
		int v;
		cin >> v;
		arr2[i] = {(double)v, 0};
	}
	reverse(arr2.begin(), arr2.end());
	int e = 0;
	while ((1 << e) < n + m)
		e++;
	arr1.resize(1 << e);
	arr2.resize(1 << e);
	auto fft1 = fft(arr1);
	auto fft2 = fft(arr2);
	for (int i = 0; i < (1 << e); i++)
		fft1[i] *= fft2[i];
	auto res = fft(fft1, -1);
	for (int i = 0; i < n + m - 1; i++)
		cout << (ll)(res[i].real() + 0.5) << " \n"[i == n + m - 2];
}
