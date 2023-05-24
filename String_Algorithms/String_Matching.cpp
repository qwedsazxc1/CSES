#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string str){
	vector<int> res(str.size());
	for (int i = 1, j = 0; i < res.size(); i++){
		while (str[i] != str[j] && j != 0){ j = res[j - 1];}
		if (str[i] == str[j]) j++;
		res[i] = j;
	}
	return res;
}

int main(){
	string str, tar;
	cin >> str >> tar;
	string temp = tar + "/" + str;
	vector<int> res = kmp(temp);
	int ans = 0;
	for (int i = tar.size() + 1; i < res.size(); i++){
		if (res[i] == tar.size())
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
