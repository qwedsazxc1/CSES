#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;
	map<ll, pair<int, int>> m;
	for (int i = 1; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			ll sum = arr[i] + arr[j];
			auto it = m.find(k - sum);
			if (it != m.end()){
				cout << i + 1 << " " << j + 1 << " " << it->second.first + 1 << " " << it->second.second + 1 << "\n";
				return 0;
			}
		}
		for (int k = i - 1; k >= 0; k--){
			m[arr[i] + arr[k]] = {i, k};
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
