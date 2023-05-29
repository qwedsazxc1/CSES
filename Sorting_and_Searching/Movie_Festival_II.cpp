#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
   	for (int i = 0; i < n; i++){
		int start, end;
		cin >> start >> end;
		arr[i].second = start;
		arr[i].first = end;
	} 	
	sort(arr.begin(), arr.end());
	multiset<int> s;
	s.insert(-1);
	int ans = 0;
	for (int i = 0; i < n; i++){
		int start = arr[i].second, end = arr[i].first;
		auto it = s.upper_bound(start);
		// not found
		if (it == s.begin()){
			if (s.size() == k)
				continue;
			else {
				s.insert(end);
				ans++;
				continue;
			}
		}
		ans++;
		it--;
		s.erase(it);
		s.insert(end);
	}
	cout << ans << "\n";
	return 0;
}
