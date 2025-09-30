#include <bits/stdc++.h>

using namespace std;

void merge_sort(vector<int> &arr, int l, int r){
	if (l == r)
		return;
	int mid = (l + r) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	vector<int> temp;
	int li = l, ri = mid + 1;
	while (li <= mid && ri <= r){
		cout << "? " << arr[li] + 1 << " " << arr[ri] + 1 << endl;
		string res;
		cin >> res;
		if (res == "YES")
			temp.push_back(arr[li++]);
		else
			temp.push_back(arr[ri++]);
	}
	while (li <= mid)
		temp.push_back(arr[li++]);
	while (ri <= r)
		temp.push_back(arr[ri++]);
	for (int i = l; i <= r; i++)
		arr[i] = temp[i - l];
}

int main(){
	int n;
	cin >> n;
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 0);
	merge_sort(ans, 0, n - 1);
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
		temp[ans[i]] = i + 1;
	ans = temp;
	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i == n - 1];
	cout.flush();
}
