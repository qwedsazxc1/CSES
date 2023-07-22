#include <bits/stdc++.h>

using namespace std;

string LPS(string &str){
	int n = (int)str.size();
	n = 2 * n + 1;
	string nstr;
	nstr.resize(n);
	
	for (int i = 0; i < n; i++){
		if (i & 1)
			nstr[i] = str[i / 2];
		else
			nstr[i] = '*';
	}

	vector<int> z(n);
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++){
		if (i > r){
			int nr = i + 1, nl = i - 1, len = 0;
			while (nr < n && nl >= 0){
				if (nstr[nl] != nstr[nr])
					break;
				len++;
				nl--;
				nr++;
			}
			z[i] = len;
			l = i - len;
			r = i + len;
			continue;
		}
		
		int mid = (l + r) / 2;
		int rl = z[r - i + l] + i;
		if (rl < r)
			z[i] = z[r - i + l];
		else if (rl > r){
			z[i] = r - i;
		}
		else{
			int nr = r + 1, nl = 2 * i - r - 1, len = r - i;
			while (nr < n && nl >= 0){
				if (nstr[nl] != nstr[nr])
					break;
				nl--;
				nr++;
				len++;
			}
			z[i] = len;
			l = i - len;
			r = i + len;
		}
	}
	
	string res;
	int max_len = -1, index = -1;
	for (int i = 0; i < n; i++){
		int temp;
		if (i & 1)
			temp = z[i] / 2 * 4 + 1;
		else
			temp = z[i] * 2;
		if (max_len < temp){
			index = i;
			max_len = temp;
		}
	}
	for (int i = index - z[index]; i < index + z[index]; i++){
		if (i & 1)
			res.push_back(nstr[i]);
	}
	return res;
}

int main(){
	string str;
	cin >> str;
	cout << LPS(str) << "\n";
	return 0;
}
