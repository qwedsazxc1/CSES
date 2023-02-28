// sources: https://cses.fi/problemset/task/1144

// task: You are given n salaries and you have to answer q queries. 
// Each query is described by one character and two integers:
// If the character is '?', you have to answer the sum of the salaries in the range [a,b].
// If the character is '!', you have to change the salary of the employee i to x.

// Input Format
// The first input line has two integers n and q: the number of salaries and queries.
// The second line has n integers s1,s2,…,sn: the salary of each employee.
// Then, there are q lines describing the queries. Each line has a character and two integers a and b: the description of the query.

// Output Format
// Print the answer to each '?'-query.

// Constraints
// 1 <= n,q <= 2*10^5
// 1 <= si <= 10^9
// 1 <= a <= b <= n
// 1 <= i <= n
// 1 <= x <= 10^9

// Example

// Input:
// 5 3
// 3 7 2 2 5
// ? 2 3
// ! 3 6
// ? 2 3

// Output:
// 3
// 2

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long long> salaries(n);
    for (int i = 0; i < n; i++) {
        cin >> salaries[i];
    }
    
}