#include <bits/stdc++.h>
using namespace std;
multiset<int> great, small;

void insert(int v){
	int mid = *small.rbegin();
	if (v > mid){
		great.insert(v);
		if (great.size() > small.size()){
			small.insert(*great.begin());
			great.erase(great.begin());
		}
	}
	else{
		small.insert(v);
		if ((int)small.size() - 2 >= (int)great.size()){
			great.insert(*small.rbegin());
			small.erase(small.find(*small.rbegin()));
		}
	}
}

void remove(int v){
	if (great.find(v) == great.end()){
		small.erase(small.find(v));
		if (small.size() < great.size()){
			small.insert(*great.begin());
			great.erase(great.begin());
		}
	}
	else{
		great.erase(great.find(v));
		if ((int)small.size() - 2 >= (int)great.size()){
			great.insert(*small.rbegin());
			small.erase(small.find(*small.rbegin()));
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	small.insert(arr[0]);
	for (int i = 1; i < m; i++)
		insert(arr[i]);
	for (int i = m; i < n; i++){
		cout << *small.rbegin() << " ";
		insert(arr[i]);
		remove(arr[i - m]);
	}
	cout << *small.rbegin() << "\n";
	return 0;
}
