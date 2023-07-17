#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void radix_sort(vector<pair<pii, int>> &arr){
	int n = (int)arr.size();
	vector<int> pos(n), cnt(n, 0);
	// sort second
	{
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.second]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.second]++] = arr[i];

		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}

	// sort first
	{
		cnt.assign(n, 0);
		for (int i = 0; i < n; i++)
			cnt[arr[i].first.first]++;
		pos[0] = 0;
		for (int i = 1; i < n; i++)
			pos[i] = pos[i - 1] + cnt[i - 1];
		
		vector<pair<pii, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[pos[arr[i].first.first]++] = arr[i];

		for (int i = 0; i < n; i++)
			arr[i] = temp[i];
	}
}

vector<int> SA(string &str){
	str += "#";
	int n = (int)str.size();
	vector<int> res(n);

	// preprocess 
	{
		vector<pair<char, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[i] = {str[i], i};
		sort(temp.begin(), temp.end());
		int cnt = 0;
		res[temp[0].second] = 0;
		for (int i = 1; i < n; i++){
			if (temp[i - 1].first == temp[i].first)
				res[temp[i].second] = cnt;
			else
				res[temp[i].second] = ++cnt;
		}
	}

	for (int k = 0; (1 << k) <= n; k++){
		vector<pair<pii, int>> label(n);
		for (int i = 0; i < n; i++)
			label[i] = {{res[i], res[(i + (1 << k)) % n]}, i};
		radix_sort(label);
		int cnt = 0;
		res[label[0].second] = 0;
		for (int i = 1; i < n; i++)
			if (label[i - 1].first == label[i].first)
				res[label[i].second] = cnt;
			else
				res[label[i].second] = ++cnt;
	}

	vector<int> sa(n);
	for (int i = 0; i < n; i++)
		sa[res[i]] = i;
	return sa;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	int q;
	cin >> str >> q;
	vector<int> sa = SA(str);
	
	while (q--){
		string pat;
		cin >> pat;
		int l = 1, r = (int)sa.size() - 1;
		for (int i = 0; i < (int)pat.size(); i++){
			if (l < 0 || r < 0 || l > r)
				break;
			int newl = -1, newr = r + 1, templ = l, tempr = r;
			while (templ <= tempr){
				int mid = (templ + tempr) / 2;
				if (sa[mid] + i < (int)str.size() && str[sa[mid] + i] < pat[i]){
					templ = mid + 1;
				}
				else{
					newl = mid;
					tempr = mid - 1;
				}
			}
			templ = l, tempr = r;
			while (templ <= tempr){
				int mid = (templ + tempr) / 2;
				if (sa[mid] + i < (int)str.size() && str[sa[mid] + i] <= pat[i]){
					templ = mid + 1;
				}
				else{
					newr = mid;
					tempr = mid - 1;
				}
			}
			l = newl, r = newr - 1;
		}
		if (l < 0 || r < 0 || l > r)
			cout << "NO\n";
		else
			cout << "YES\n";
	}	
	return 0;
}
