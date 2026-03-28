#include <bits/stdc++.h>

using namespace std;

int lim;

typedef vector <int> vi;
vector <vector <vi>> dp;

string s;
int rec(int pos, int last, bool tight, bool started){
    if(pos == lim)
        if(started) return 1;
        else return 0;

    if(dp[pos][last][started] != -1 && !tight)
        return dp[pos][last][started];

    int lim_dig = s[pos] - '0';
    if(!tight) lim_dig = 9;

    int soma = 0;
    for(int i = 0; i <= lim_dig; i++){
        // verifica condições
        soma += rec(pos + 1, i, tight && (i == s[pos] - '0'), started || (i != 0));
    }

    if(!tight) return dp[pos][last][started] = soma;
    return soma;
}

int digit_dp(int x){
    s = to_string(x);
    lim = (int) s.size();

    dp = vector <vector <vi>> (lim, vector <vi> (10, vi (2, -1)));

    return rec(0, 0, true, false);
}