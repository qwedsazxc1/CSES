#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int graph[n][30];
    for (int i = 0; i < n; i++){
        int input;
        cin >> input;
        input--;
        graph[i][0] = input; 
    }
    for (int i = 1; i < 30; i++){
        for (int j = 0; j < n; j++){
            graph[j][i] = graph[graph[j][i - 1]][i - 1];
        }
    }
    while (q--){
        int s, k;
        cin >> s >> k;
        s--;
        for (int i = 0; i < 30; i++)
            if (k & (1 << i))
                s = graph[s][i];
        cout << ++s << "\n";
    }
    return 0;
}