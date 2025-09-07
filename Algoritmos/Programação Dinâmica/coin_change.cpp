#include <bits/stdc++.h>

using namespace std;

// constantes e variaveis padroes

const int MAXN = 1e4 + 1;
const int MAXC = 1e4 + 1;
int n, c;

int coins[MAXN];

// DP matriz (espaço o(n * m));


void dp_vetor(){
    vector <int> dp(c + 1, c + 10);

    dp[0] = 0;
    for(int i = 0; i < c; ++i){
        if (dp[i] != c + 10){
            for(int j = 0; j < n; ++j){
                int pos = i + coins[j];
                if(pos <= c) dp[pos] = min(dp[pos], dp[i] + 1);
            }
        }
    }

    if (dp[c] == c + 10) cout << "-1\n";
    cout << dp[c] << "\n";
}

int main(){
    cin >> n >> c;
    
    for(int i = 0; i < n; ++i) cin >> coins[i];

    dp_vetor();

    return 0;
}