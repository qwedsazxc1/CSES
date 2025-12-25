#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	bool A, T, C, G;
	A = T = C = G = false;
	string ans;
	for (int i = 0; i < (int)str.size(); i++){
		if (str[i] == 'A')
			A = true;
		if (str[i] == 'T')
			T = true;
		if (str[i] == 'C')
			C = true;
		if (str[i] == 'G')
			G = true;
		if (A && T && C && G){
			ans.push_back(str[i]);
			A = T = C = G = false;
		}
	}
	if (!A) 
		ans.push_back('A');
	else if (!T)
		ans.push_back('T');
	else if (!C)
		ans.push_back('C');
	else if (!G)
		ans.push_back('G');
	
	cout << ans << "\n";
	return 0;
}
