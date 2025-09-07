#include <bits/stdc++.h>

const int MAXN = 16;
const int MAXM = (1 << 15) + 1;

using namespace std;

int n, m;
int mat[MAXN][MAXN], dp[MAXN][MAXM];

int solve(int i, int mask){
    if ((1 << n) - 1 == mask) return dp[i][mask] = 0;

    if(dp[i][mask] != -1) return dp[i][mask];

    int asw = 1e9;

    for(int v = 0; v < n; ++v){
        if(mask & (1 << v) || !mat[i][v]) continue;

        asw = min(asw, solve(v, (mask | (1 << v))) + mat[i][v]);
    }

    return dp[i][mask] = asw;
}

int main(){
    cin >> n >> m;

    int a, b, peso;
    while(m--){
        cin >> a >> b >> peso;
        mat[a][b] = mat[b][a] = peso;
    }
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 1);
}