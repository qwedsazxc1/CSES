#include <bits/stdc++.h>

using namespace std;

vector<int> Z(string &str){
	int n = str.size();
	vector<int> z(n);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++){
		z[i] = max(0, min(z[i - x], y - i + 1));
		while (z[i] + i < n && str[z[i]] == str[z[i] + i])
			x = i, y = i + z[i], z[i]++;
	}
	return z;
}

int main(){
	string str;
	cin >> str;
	vector<int> z = Z(str);
	int n = z.size();
	for (int i = 0; i < n - 1; i++){
		if (z[n - i - 1] == i + 1)
			cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}
