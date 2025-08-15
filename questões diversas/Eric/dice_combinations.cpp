#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 1;
 
int main()
{
    int n;
    cin >> n;
    
    long long dp[MAX];
    dp[0] = 1;
    
    int i = 1;
    while(i <= n && i < 6){
        dp[i] = 0;
        for(int j = 1; j <= i; ++j){
            dp[i] += dp[i - j];
        }
        ++i;
    }
    for(; i <= n; ++i){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) % MOD;
    }
    
    cout << dp[n] << "\n";
    return 0;
}