#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	int n = str.size();
	int cnt[26] = {};
	for (int i = 0; i < n; i++)
		cnt[str[i] - 'A']++;
	int maxnum = 0, index;
	for (int i = 0; i < 26; i++){
		if (maxnum < cnt[i]){
			maxnum = cnt[i];
			index = i;
		}
	}
	if (maxnum > n / 2 + (n & 1)){
		cout << "-1\n";
		return 0;
	}
	int left = n;
	char prev = '*';
	string ans;
	while (left > 0){
		if (left & 1 && left / 2 + 1 == maxnum){
			ans.push_back(index + 'A');
			prev = index + 'A';
			left--;
			cnt[index]--;
		}
		else{
			int j = 0;
			for (; j < 26; j++){
				if (cnt[j] > 0 && j + 'A' != prev)
					break;
			}
			cnt[j]--;
			left--;
			prev = j + 'A';
			ans.push_back(j + 'A');
		}
		maxnum = 0;
		for (int i = 0; i < 26; i++){
			if (maxnum < cnt[i]){
				maxnum = cnt[i];
				index = i;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
