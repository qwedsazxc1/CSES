#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

struct union_and_find{
    vector<int> parent;
    vector<int> size;
    int group_num;
    void init(int arr_size){
        parent.resize(arr_size);
        size.resize(arr_size);
        for (int i = 0; i < arr_size; i++){
            parent[i] = i;
            size[i] = 1;
        }
        group_num = arr_size;
    }
    int find(int target){
        if (parent[target] == target){
            return target;
        }
        return parent[target] = find(parent[target]);
    }
    int __union(int a, int b){
        int a_boss = find(a), b_boss = find(b);
        if (a_boss == b_boss)
            return a_boss;
        if (size[a_boss] > size[b_boss])
            swap(a_boss, b_boss);
        parent[a_boss] = b_boss;
        size[b_boss] += size[a_boss];
        group_num -= 1;
        return b_boss;
    }
};


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    union_and_find dsu;
    dsu.init(n);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        dsu.__union(a - 1, b - 1);
    }
    printf("%d\n", dsu.group_num - 1);
    int hold;
    for (int i = 0; i < n; i++){
        if (dsu.parent[i] == i){
            hold = i;
            break;
        }
    }
    while (dsu.group_num > 1){
        int i;
        for (i = hold + 1; i < n; i++){
            if (dsu.parent[i] != i)
                continue;
            printf("%d %d\n", hold + 1, i + 1);
            hold = dsu.__union(hold, i);
        }
    }
    return 0;
}