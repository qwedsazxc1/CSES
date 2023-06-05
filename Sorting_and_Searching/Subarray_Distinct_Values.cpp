#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	vector<int> arr(n);
	for (auto &x: arr)
		cin >> x;
	map<int, int> m, locate;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++){
		if (m.find(arr[i]) != m.end()){
			locate.erase(m[arr[i]]);
		}
		locate[i] = arr[i];
		m[arr[i]] = i;
		if (m.size() > k){
			int era_element = (*locate.begin()).second, next_index = locate.begin()->first;
			l = next_index + 1;
			m.erase(era_element);
			locate.erase(locate.begin());
		}
		ans += i - l + 1;
	}
	cout << ans << "\n";
	return 0;
}
