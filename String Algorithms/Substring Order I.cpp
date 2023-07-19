#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void radix_sort(vector<pair<pii, int>> &arr){
	int n = (int)arr.size();
	vector<int> cnt(n, 0), pos(n);
	// sort second
	{
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.second]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.second]++] = arr[i];
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
	// sort first
	{
		cnt.assign(n, 0);
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.first]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.first]++] = arr[i];
		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
}

vector<int> SA(string &str){
	str += "*";
	int n = (int)str.size();
	vector<int> res(n);
	// preprocess
	{
		vector<pair<char, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[i] = {str[i], i};
		sort(temp.begin(), temp.end());
		res[temp[0].second] = 0;
		int cnt = 0;
		for (int i = 1; i < n; i++)
			if (temp[i].first == temp[i - 1].first)
				res[temp[i].second] = cnt;
			else
				res[temp[i].second] = ++cnt;
	}

	for (int k = 0; (1 << k) <= n; k++){
		vector<pair<pii, int>> label(n);
		for (int i = 0; i < n; i++)
			label[i] = {{res[i], res[(i + (1 << k)) % n]}, i};
		radix_sort(label);
		int cnt = 0;
		res[label[0].second] = 0;
		for (int i = 1; i < n; i++)
			if (label[i].first == label[i - 1].first)
				res[label[i].second] = cnt;
			else
				res[label[i].second] = ++cnt;
	}

	vector<int> sa(n);
	for (int i = 0; i < n; i++)
		sa[res[i]] = i;
	return sa;
}

vector<int> LCP(vector<int> &sa, string &str){
	int n = (int)sa.size();
	vector<int> order(n), lcp(n, 0);
	for (int i = 0; i < n; i++)
		order[sa[i]] = i;
	int pre = 0;
	for (int i = 0; i < n - 1; i++){
		if (order[i] == n - 1)
			continue;
		if (pre > 0) pre--;
		int j = sa[order[i] + 1];
		while (j + pre < n && i + pre < n && str[i + pre] == str[j + pre])
			pre++;
		lcp[order[i]] = pre;
	}
	return lcp;
}

int main(){
	long long k;
	string str;
	cin >> str >> k;
	vector<int> sa = SA(str);
	vector<int> lcp = LCP(sa, str);
	long long n = (long long)sa.size();
	for (int i = 1; i < n; i++){
		if (k > n - sa[i] - 1){
			k -= n - sa[i] - 1 - lcp[i];
			continue;
		}
		int l = sa[i], r = l + k;
		for (int i = l; i < r; i++)
			cout << str[i];
		cout << "\n";
		break;
	}
	return 0;
}
