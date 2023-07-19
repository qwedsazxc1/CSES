#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

void radix_sort(vector<pair<pii, int>> &arr){
	int n = (int)arr.size();
	vector<int> cnt(n, 0), pos(n);
	// sort second
	{
		vector<pair<pii, int>> temp(n);
		for (auto x: arr)
			cnt[x.first.second]++;
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
		for (auto x: arr)
			cnt[x.first.first]++;
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
	// preproess
	{
		vector<pair<char, int>> temp(n);
		for (int i = 0; i < n; i++)
			temp[i] = {str[i], i};
		sort(temp.begin(), temp.end());
		int cnt = 0;
		res[0] = 0;
		for (int i = 1; i < n; i++){
			if (temp[i].first == temp[i - 1].first)
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
			if (l > r)
				break;
			int newl = r + 1, newr = r + 1, templ = l, tempr = r;
			while (templ <= tempr){
				int mid = (templ + tempr) / 2;
				if (i + sa[mid] < (int)str.size() && str[i + sa[mid]] < pat[i]){
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
				if (i + sa[mid] < (int)str.size() && str[i + sa[mid]] <= pat[i]){
					templ = mid + 1;
				}
				else{
					newr = mid;
					tempr = mid - 1;
				}
			}
			l = newl, r = newr - 1;
		}
		cout << ((r - l < 0) ? 0 : r - l + 1) << "\n";
	}
	return 0;
}
