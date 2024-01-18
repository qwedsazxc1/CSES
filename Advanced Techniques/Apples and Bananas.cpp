#include <bits/stdc++.h>

using namespace std;
typedef complex<double> cd;

const double pi = acos(-1);

vector<cd> fft(vector<cd> arr, int d){
	int n = arr.size();
	vector<cd> r(n);
	for (int k = 0; k < n; k++){
		int b = 0;
		for (int z = 1; z < n; z *= 2){
			b *= 2;
			if (k & z)
				b++;
		}
		r[b] = arr[k];
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
	if (d == -1){
		for (int i = 0; i < n; i++)
			r[i] /= n;
	}
	return r;
}

int main(){ 
	int k, n, m;
	cin >> k >> n >> m;
	int powerof2 = 0;
	for (powerof2 = 0; (1 << powerof2) < 2 * k; powerof2++);
	vector<cd> apple(1 << powerof2), banana(1 << powerof2);
	for (int i = 0; i < n; i++){
		int in;
		cin >> in;
		in--;
		apple[in] += (cd){1, 0};
	}
	for (int i = 0; i < m; i++){
		int in;
		cin >> in;
		in--;
		banana[in] += (cd){1, 0};
	}
	vector<cd> arr1 = fft(apple, 1), arr2 = fft(banana, 1);
	for (int i = 0; i < (1 << powerof2); i++)
		arr1[i] *= arr2[i];
	vector<cd> ans = fft(arr1, -1);
	for (int i = 0; i < 2 * k - 1; i++)
		cout << (long long)(ans[i].real() + 0.5) << " ";
	cout << "\n";
	return 0;
}
