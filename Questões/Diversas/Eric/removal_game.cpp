#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const int MAXN = 5000;

const ll MAXVAL = 1e15;
const pll MAXPAR = pll(MAXVAL, MAXVAL);

pll dp[MAXN][MAXN];
ll v[MAXN];

pll maior_remocao(int i, int j,bool prim){ // 1 first, 0 second;
    if (i == j) return make_pair(v[i] * prim, v[i] * !prim);
    if (dp[i][j] != MAXPAR) return dp[i][j];

    pll par_esq;
    pll par_dir;

    if(prim){
        par_esq = maior_remocao(i + 1, j, 0);
        par_dir = maior_remocao(i, j - 1, 0);

        if (v[i] + par_esq.first > v[j] + par_dir.first){
            par_esq.first += v[i];
            return dp[i][j] = par_esq;
        } else {
            par_dir.first += v[j];
            return dp[i][j] = par_dir;
        }
    } else {
        par_esq = maior_remocao(i + 1, j, 1);
        par_dir = maior_remocao(i, j - 1, 1);

        if (v[i] + par_esq.second > v[j] + par_dir.second){
            par_esq.second += v[i];
            return dp[i][j] = par_esq;
        } else {
            par_dir.second += v[j];
            return dp[i][j] = par_dir;
        }
    }
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; ++i) cin >> v[i];

    for(int i = 0; i <n; ++i)
    for(int j = 0; j <n; ++j)
    dp[i][j] = MAXPAR;

    cout << maior_remocao(0, n - 1, 1).first <<"\n";

    return 0;
}