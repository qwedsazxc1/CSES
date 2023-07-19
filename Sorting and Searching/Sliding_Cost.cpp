#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
multiset<ll> low, high;
ll cost = 0, avr, low_sum = 0, high_sum = 0;

void insert(ll x){
	auto med = low.rbegin();
	if (x > *med){
		high.insert(x);
		high_sum += x;
		if (high.size() > low.size()){
			high_sum -= *high.begin();
			low_sum += *high.begin();
			low.insert(*high.begin());
			high.erase(high.begin());
		}
	}
	else{
		low_sum += x;
		low.insert(x);
		if ((int)low.size() - 2 == (int)high.size()){
			high_sum += *low.rbegin();
			low_sum -= *low.rbegin();
			high.insert(*low.rbegin());
			low.erase(--low.end());
		}
	}
	avr = *low.rbegin();
	cost = avr * low.size() - low_sum + high_sum - avr * high.size();
}

void remove(ll x){	
	if (high.find(x) == high.end()){
		low_sum -= x;
		low.erase(low.find(x));
		if (low.size() < high.size()){
			high_sum -= *high.begin();
			low_sum += *high.begin();
			low.insert(*high.begin());
			high.erase(high.begin());
		}
	}
	else{
		high_sum -= x;
		high.erase(high.find(x));
		if ((int)low.size() - 2 == (int)high.size()){
			high_sum += *low.rbegin();
			low_sum -= *low.rbegin();
			high.insert(*low.rbegin());
			low.erase(--low.end());	
		}
	}
	avr = *low.rbegin();
	cost = avr * low.size() - low_sum + high_sum - avr * high.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &x: arr)
		cin >> x;
	low.insert(arr[0]);
	avr = arr[0]; low_sum = arr[0];
	for (int i = 1; i < k; i++){
		insert(arr[i]);
	}
	for (int i = k; i < n; i++){
		cout << cost << " ";
		insert(arr[i]);
		remove(arr[i - k]);
	}
	cout << cost << "\n";
	return 0;
}
