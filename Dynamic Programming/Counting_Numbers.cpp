#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long sum(long long num, vector<long long> &dp){
    if (num < 1)
        return num == 0 ? 1 : 0;
    string str = to_string(num);
    long long ans = 0;
    for (int i = 0; i < str.size(); i++){
        ans += dp[i];
    }
    int prev = 0;
    for (int i = 0; i < str.size(); i++){
        int digit = str[i] - '0';
        int dp_index = (str.size() - i - 1);
        int new_digit = (digit > prev) ? digit - 1 : digit;
        if (digit != 0)
            ans += new_digit * dp[dp_index];
        if (digit == prev)
            return ans;
        prev = digit;
    }
    return ans + 1;
}

int main(){
    vector<long long> dp(19);
    dp[0] = 1;
    for (int i = 1; i < 19; i++){
        dp[i] = dp[i - 1] * 9LL;
    }
    long long a, b;
    cin >> a >> b;
    cout << sum(b, dp) - sum(a - 1, dp) << "\n";
    return 0;
}