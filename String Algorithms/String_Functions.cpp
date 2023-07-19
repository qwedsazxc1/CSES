#include <bits/stdc++.h>

using namespace std;

vector<int> Z(string &str){
	int n = str.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (z[i] + i < n && str[z[i]] == str[i + z[i]]){
			r = z[i] + i;
			z[i]++;
			l = i;
		}
	}
	return z;
}

vector<int> pi(string &str){
	int n = str.size();
	vector<int> k(n);
	for (int i = 1, cur = 0; i < n; i++){
		while (cur > 0 && str[i] != str[cur]) {cur = k[cur - 1];}
		if (str[i] == str[cur])
			cur++;
		k[i] = cur;
	}
	return k;
}

int main(){
	string str;
	cin >> str;
	vector<int> z = Z(str), k = pi(str);

	for (int i = 0; i < z.size(); i++)
		cout << z[i] << " ";
	cout << "\n";
	for (int i = 0; i < k.size(); i++)
		cout << k[i] << " ";
	cout << "\n";

	return 0;
}
