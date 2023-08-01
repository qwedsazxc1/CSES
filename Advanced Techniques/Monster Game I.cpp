#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// represent ax + b
struct line{
	ll a, b;
};

ll intersect(line a, line b){
	ll res;
	res = ceil((double)(b.b - a.b) / (a.a - b.a));
	return res;
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> s(n), f(n);
	for (auto &x: s)
		cin >> x;
	for (auto &x: f)
		cin >> x;
	vector<ll> range;
	vector<line> lines;
	range.push_back(0);
	lines.push_back({x, 0});
	for (int i = 0; i < n - 1; i++){
		if (lines.back().a == f[i])
			continue;
		int index = upper_bound(range.begin(), range.end(), s[i]) - 1 - range.begin();
		ll newa = f[i], newb = lines[index].b + lines[index].a * s[i];
		line new_line = {newa, newb};
		while (range.size() >= 2){
			ll x1 = intersect(new_line, lines[lines.size() - 1]);
			ll x2 = range.back();
			if (x1 <= x2){
				lines.pop_back();
				range.pop_back();
				continue;
			}
			break;
		}
		ll x = intersect(new_line, lines[lines.size() - 1]);	
		lines.push_back(new_line);
		range.push_back(x);
	}
	
	int index = upper_bound(range.begin(), range.end(), s[n - 1]) - 1 - range.begin();
	cout << lines[index].a * s[n - 1] + lines[index].b << "\n";
	return 0;
}
