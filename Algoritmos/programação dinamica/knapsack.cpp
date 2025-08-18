#include <bits/stdc++.h>

using namespace std;
const int MAXN = 101;
const int MAXC = 100001;
const long long inf = 0x3f3f3f3f3f3f3f3f; // ~= 10^18

int n, c;
int valores[MAXN], pesos[MAXN];
long long dp[MAXN][MAXC];

int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; ++i){
        cin >> pesos[i] >> valores[i];
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= c; ++j)
            dp[i][j] = -inf;
    
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= c; ++j){
            dp[i][j] = dp[i - 1][j];

            if(j >= pesos[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - pesos[i]] + valores[i]);
        }
    }

    cout << dp[n][c] << "\n";

    return 0;
}