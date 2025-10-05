#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct union_find_roll{
    vector<int> pa_sz;
    stack<pair<int, int>> history;
    union_find_roll(int n) : pa_sz(n, -1) {}
    int find(int a){
        if (pa_sz[a] < 0)
            return a;
        return find(pa_sz[a]);
    }
    int merge(int a, int b){
        a = find(a);
        b = find(b);
        if (a == b)
            return 0;
        if (pa_sz[a] > pa_sz[b])
            swap(a, b);
        history.push({a, pa_sz[a]});
        history.push({b, pa_sz[b]});
        pa_sz[a] += pa_sz[b];
        pa_sz[b] = a;
        return 1;
    }
    void rollback(){
        if (history.empty())
            return;
        for (int i = 0; i < 2; i++){
            auto p = history.top();
            history.pop();
            pa_sz[p.first] = p.second;
        }
    }
};

struct edge{
    int u, v;
    ll w;
};

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<edge> ori(m), sorted(m);
    map<ll, vector<int>> em;
    for (int i = 0; i < m; i++){
        cin >> ori[i].u >> ori[i].v >> ori[i].w;
        ori[i].u--; ori[i].v--;
        em[ori[i].w].push_back(i);
    }
    sorted = ori;
    sort(sorted.begin(), sorted.end(), [](auto &a, auto &b){
        return a.w < b.w;
    });
    vector<vector<int>> queries(q);
    vector<int> ans(q, 1);
    map<ll, vector<pair<int, int>>> qm;
    for (int i = 0; i < q; i++){
        int k;
        cin >> k;
        queries[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> queries[i][j];
            queries[i][j]--;
            qm[ori[queries[i][j]].w].push_back({i, queries[i][j]});
        }
    }
    union_find_roll dsu(n);
    int idx = 0;
    for (auto &[w, qv] : qm){
        while (idx < m && sorted[idx].w < w){
            dsu.merge(sorted[idx].u, sorted[idx].v);
            idx++;
        }
        int j = 0, qid = -1;
        vector<int> group;
        while (j < (int)qv.size()){
            if (qid != qv[j].first){
                if (qid != -1){
                    int cnt = 0;
                    for (auto &eidx : group){
                        auto &e = ori[eidx];
                        if (!dsu.merge(e.u, e.v)){
                            ans[qid] = 0;
                            break;
                        }
                        else
                            cnt++;
                    }
                    for (int k = 0; k < cnt; k++)
                        dsu.rollback();
                }
                qid = qv[j].first;
                group.clear();
            }
            group.push_back(qv[j].second);
            j++;
        }
        if (qid != -1){
            int cnt = 0;
            for (auto &eidx : group){
                auto &e = ori[eidx];
                if (!dsu.merge(e.u, e.v)){
                    ans[qid] = 0;
                    break;
                }
                else
                    cnt++;
            }
            for (int k = 0; k < cnt; k++)
                dsu.rollback();
        }
    }
    for (auto &res : ans)
        cout << (res ? "YES" : "NO") << "\n";
    return 0;
}