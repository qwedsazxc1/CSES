#include <bits/stdc++.h>

using namespace std;

list<int> l;

list<int>::iterator move_foward(list<int>::iterator it){
	it++;
	if (it == l.end())
		it = l.begin();
	return it;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		l.push_back(i);
	auto it = l.begin();
	it = move_foward(it);
	while (l.size() > 0){
		auto temp = it;
		cout << *temp << " ";
		it = move_foward(it);
		l.erase(temp);
		it = move_foward(it);
	}
	cout << "\n";
	return 0;
}
