#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> Z(string &str){
	int n = str.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++){
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (z[i] + i < n && str[z[i] + i] == str[z[i]])
			l = i, r = z[i] + i, z[i]++;
	}
	return z;
}


int main(){
	string str;
	cin >> str;
	int n = str.size();
	vector<int> z = Z(str);
	for (int i = 0; i < n; i++){
		int cur_index = i + 1;
		bool flag = true;
		while (cur_index < n){
			int len = min(i + 1, n - cur_index);
			if (z[cur_index] < len){flag = false; break;}
			cur_index += len;
		}
		if (flag)
			cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}
