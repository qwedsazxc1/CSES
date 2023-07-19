// Author: keep1earning

// Problem: Edit Distance
// Problem Link: https://cses.fi/problemset/task/1639

// this is a dynamic programming problem
// the solution is to use a 2d array to store the minimum number of operations
// to convert the first i characters of the first string to the first j characters of the second string
// the operations are insert, delete, and replace
// the solution is to use the minimum of the three operations
// the time complexity is O(nm) where n is the length of the first string and m is the length of the second string
// the space complexity is O(nm)

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int min(int a, int b){
    if (a > b)
        return b;
    return a;
}


int main(){
    // input
    string n, m;
    cin >> n >> m;

    // space for dp array
    int dp[n.length() + 1][m.length() + 1] = {};

    // base cases
    for (int i = 1; i <= n.size(); i++){
        dp[i][0] = i;
    }
    for (int i = 1; i <= m.size(); i++){
        dp[0][i] = i;
    }

    // dynamic programming
    for (int i = 1; i <= n.size(); i++){
        for (int j = 1; j <= m.size(); j++){
            int cost = 1;
            if (n[i - 1] == m[j - 1])
                cost = 0;
            
            // minimum of insert, delete, and replace
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost));
        }
    }

    // output
    cout << dp[n.size()][m.size()] << '\n';
    return 0;
}