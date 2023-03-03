#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct edge{
    int from, to;
    long long weight;
};


bool cmp(struct edge a, struct edge b){
    return a.weight < b.weight;
}   

class union_and_find{
private:
    vector<int> size;
    vector<int> parent;
    int set_amount;
public:
    union_and_find(int size){
        this->size.resize(size);
        parent.resize(size);
        set_amount = size;
        for (int i = 0; i < size; i++)
            parent[i] = i, this->size[i] = 1;
    }
    int find(int a){
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    bool merge(int a, int b){
        int a_boss = find(a), b_boss = find(b);
        if (a_boss == b_boss)
            return false;
        if (size[a_boss] > size[b_boss])
            swap(a_boss, b_boss);
        parent[a_boss] = b_boss;
        size[b_boss] += size[a_boss];
        set_amount -= 1;
        return true;
    }
    int get_set_amount(){
        return set_amount;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<edge> graph(m);
    union_and_find dsu(n);
    for (int i = 0; i < m; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        a--; b--;
        graph[i].from = a, graph[i].to = b, graph[i].weight = weight;
    }
    sort(graph.begin(), graph.end(), cmp);
    long long ans = 0;
    for (auto e: graph){
        if (dsu.merge(e.from, e.to))
            ans += e.weight;
    }
    if (dsu.get_set_amount() != 1)
        cout << "IMPOSSIBLE\n";
    
    else
        cout << ans << "\n";
    return 0;
}
