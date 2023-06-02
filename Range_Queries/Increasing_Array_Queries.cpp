#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define id second
using namespace std;

typedef long long ll;
int maxn;
vector<ll> bit;

void update(int k, ll x){
	for (; k <= maxn; k += k & -k)
		bit[k] += x;
}

ll query(int qr){
	ll res = 0;
	for (; qr > 0; qr -= qr & -qr)
		res += bit[qr];
	return res;
}

ll query(int ql, int qr){
	return query(ql - 1) + query(qr);
}

int main(){
	int n, q;
	cin >> n >> q;
	maxn = n + 1;
	vector<ll> arr(n + 2), prefix(n + 2), ans(q + 1), add(n + 1);
	bit.assign(n + 2, 0);
	vector<vector<pair<int, int>>> que(n + 1);
	prefix[0] = 0;
	arr[n + 1] = INF;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		prefix[i] = arr[i] + prefix[i - 1];
	}
	prefix[n + 1] = prefix[n] + arr[n + 1];
	for (int i = 1; i <= q; i++){
		int ql, qr;
		cin >> ql >> qr;
		que[ql].push_back({qr, i});
	}
	deque<int> stk = {n + 1};
	for (int i = n; i > 0; i--){
		int f;
		while (arr[i] >= arr[(f = stk.front())]){
			stk.pop_front();
			update(f, -add[f]);
		}

		add[i] = (stk.front() - i) * arr[i] - (prefix[stk.front() - 1] - prefix[i - 1]);
		update(i, add[i]);
		stk.push_front(i);
		for (auto p: que[i]){
			int pos = upper_bound(stk.begin(), stk.end(), p.first) - stk.begin() - 1;
			if (pos == 0)
				ans[p.id] = 0;
			else
				ans[p.id] = query(i, stk[pos - 1]);
			
			ans[p.id] += (p.first - stk[pos] + 1) * arr[stk[pos]] - (prefix[p.first] - prefix[stk[pos] - 1]);
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << "\n";
	return 0;
}
