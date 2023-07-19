#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0, max = -1;
    for (int i = 0; i < n; i++){
        long long input;
        cin >> input;
        if (max < input)
            max = input;
        sum += input;
    }
    sum -= max;
    if (sum <= max){
        cout << 2 * max << "\n";
    }
    else
        cout << sum + max << "\n";
    return 0;
}