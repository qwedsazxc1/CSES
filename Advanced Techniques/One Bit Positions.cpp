#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> cd;
const double pi = acos(-1);

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
		cd wm = exp(cd{0, d * 2 * pi / m});
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
	string str;
	cin >> str;
	int n = str.size();
	vector<cd> cnt1(n), cnt2(n);
	for (int i = 0; i < n; i++)
		if (str[i] == '1'){
			cnt1[i] = {1, 0};
			cnt2[n - i - 1] = {1, 0};
		}
	int e = 0;
	while ((1 << e) < 2 *  n)
		e++;
	cnt1.resize(1 << e);
	cnt2.resize(1 << e);
	vector<cd> fft1, fft2;
	fft1 = fft(cnt1);
	fft2 = fft(cnt2);
	vector<cd> fftres(1 << e);
	for (int i = 0; i < (1 << e); i++)
		fftres[i] = fft1[i] * fft2[i];
	vector<cd> res = fft(fftres, -1);
	for (int i = 1; i < n; i++)
		cout << (int)(0.5 + res[n + i - 1].real()) << " \n"[i == n - 1];
}
