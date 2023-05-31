#include <bits/stdc++.h>

using namespace std;

long long a = 0;

void merge_sort(vector<int> &arr);

void divide(vector<int> &arr, int l, int r);
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<bool> visited(n, false);
	int b = 0, c, d = n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	// count d
	for (int i = n - 1; i >= 0; i--){
		if (arr[i] == d)
			d--;
	}

	// count b
	for (int i = 0; i < n; i++){
		if (visited[i])
			continue;
		visited[i] = true;
		int s = i + 1, temp;
		temp = s;
		while (s != arr[temp - 1]){
			b++;
			temp = arr[temp - 1];
			visited[temp - 1] = true;
		}
	}

	// count c
	vector<int> lis;
	lis.reserve(n);
	lis.push_back(arr[0]);
	for (int i = 1; i < n; i++){
		int l = 0, r = lis.size() - 1, res = -1;
		while (l <= r){
			int mid = (l + r) / 2;
			if (arr[i] > lis[mid]){
				l = mid + 1;
			}
			else{
				res = mid;
				r = mid - 1;
			}
		}
		if (res == -1)
			lis.push_back(arr[i]);
		else
			lis[res] = arr[i];
	}
	c = n - lis.size();

	// count a
	merge_sort(arr);

	cout << a << " " << b << " " << c << " " << d << "\n";
	return 0;
}

void merge_sort(vector<int> &arr){
	int l = 0, r = arr.size() - 1;
	if (r == 1)
		return;
	divide(arr, l, r);

}

void divide(vector<int> &arr, int l, int r){
	if (l == r)
		return;
	int mid = (l + r) / 2;
	divide(arr, l, mid);
	divide(arr, mid + 1, r);


	vector<int> temp;
	temp.reserve(r - l + 1);
	// conquer
	int li = l, ri = mid + 1;
	for (int i = 0; i < r - l + 1; i++){
		if (li == mid + 1){
			temp.push_back(arr[ri++]);
			continue;
		}
		if (ri == r + 1){
			a += (long long)r - mid;
			temp.push_back(arr[li++]);
			continue;
		}
		if (arr[li] > arr[ri]){
			temp.push_back(arr[ri++]);
		}
		else{
			a += (long long)ri - mid - 1;
			temp.push_back(arr[li++]);
		}
	}
	for (int i = l; i <= r; i++){
		arr[i] = temp[i - l];
	}
}
