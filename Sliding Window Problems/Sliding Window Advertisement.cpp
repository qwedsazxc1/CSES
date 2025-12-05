#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

struct line{
	ll a, b;
	ll f(ll x){
		return a * x + b;
	}
	line(ll a = 0, ll b = -INF): a(a), b(b) {}
};

struct node{
	line ln, tag;
};

vector<node> tree;

void push(int cur, int l, int r){
	if (tree[cur].tag.a == 0 && tree[cur].tag.b == -INF)
		return;
	line temp = tree[cur].tag;
	tree[cur].tag = line();
	int mid = (l + r) / 2;
	if (tree[cur].ln.f(mid) < temp.f(mid))
		swap(tree[cur].ln, temp);
	if (l == r)
		return;
	if (tree[cur].ln.a < temp.a){
		push(cur * 2 + 1, l, mid);
		tree[cur * 2 + 1].tag = temp;
		push(cur * 2 + 1, l, mid);
	}
	else{
		push(cur * 2 + 2, mid + 1, r);
		tree[cur * 2 + 2].tag = temp;
		push(cur * 2 + 2, mid + 1, r);
	}
}

void update(int cur, int l, int r, int ql, int qr, line x){
	push(cur, l, r);
	if (l >= ql && r <= qr){
		tree[cur].tag = x;
		push(cur, l, r);
		return;
	}
	if (r < ql || l > qr)
		return;
	int mid = (l + r) / 2;
	update(cur * 2 + 1, l, mid, ql, qr, x);
	update(cur * 2 + 2, mid + 1, r, ql, qr, x);
}

ll query(int cur, int l, int r, int k){
	push(cur, l, r);
	if (l > k || r < k)
		return -INF;
	if (l == r)
		return tree[cur].ln.f(k);
	int mid = (l + r) / 2;
	return max(max(query(cur * 2 + 1, l, mid, k), query(cur * 2 + 2, mid + 1, r, k)), tree[cur].ln.f(k));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	tree.resize((n - k + 1) << 2);
	vector<ll> arr(n);
	for (auto &x : arr)
		cin >> x;
	vector<ll> L(n), R(n);
	stack<ll> s;
	for (int i = 0; i < n; i++){
		while (s.size() && arr[s.top()] >= arr[i]){
			s.pop();
		}
		if (s.size()){
			L[i] = s.top() + 1;
		}
		else{
			L[i] = 0;
		}
		s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (int i = n - 1; i >= 0; i--){
		while (s.size() && arr[s.top()] >= arr[i]){
			s.pop();
		}
		if (s.size()){
			R[i] = s.top() - 1;
		}
		else{
			R[i] = n - 1;
		}
		s.push(i);
	}
	for (int i = 0; i < n ; i++){
		int len = R[i] - L[i] + 1;
		ll v = arr[i] * len;
		if (len >= k){
			v = k * arr[i];
			update(0, 0, n - k, 0, L[i], line(arr[i], v - L[i] * arr[i]));
			update(0, 0, n - k, L[i], R[i] - k + 1, line(0, v));
			update(0, 0, n - k, R[i] - k + 1, n - k, line(-arr[i], v + arr[i] * (R[i] - k + 1)));
		}
		else{
			if (R[i] - k + 1 >= 0)
				update(0, 0, n - k, 0, R[i] - k + 1, line(arr[i], v - arr[i] * (R[i] - k + 1)));
			
			update(0, 0, n - k, max(0LL, R[i] - k + 1), min((ll)n - k, L[i]), line(0, v));
			if (L[i] <= n - k)
				update(0, 0, n - k, L[i], n - k, line(-arr[i], v + arr[i] * (L[i])));
		}
	}
	for (int i = 0; i < n - k + 1; i++)
		cout << query(0, 0, n - k, i) << " \n"[i == n - k];
}
