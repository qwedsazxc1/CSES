#include <iostream>
#include <vector>

using namespace std;

class union_and_find{
    private:
        vector<int> parent;
        vector<int> size;
        int _max_size;
        int _group;
    public:
    union_and_find(int size){
        parent.resize(size);
        _max_size = 1;
        _group = size;
        this->size.assign(size, 1);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }  
    int find(int node){
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    bool merge(int a, int b){
        int a_boss = find(a), b_boss = find(b);
        if (a_boss == b_boss)
            return false;
        if (size[a_boss] > size[b_boss])
            swap(a_boss, b_boss);
        size[b_boss] += size[a_boss];
        _max_size = max(size[b_boss], _max_size);
        parent[a_boss] = b_boss;
        _group--;
        return true;
    }
    int group(){
        return _group;
    }
    int max_size(){
        return _max_size;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    union_and_find dsu(n);
    while (m--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        dsu.merge(a, b);
        cout << dsu.group() << " " << dsu.max_size() << "\n";
    }
    return 0;
}