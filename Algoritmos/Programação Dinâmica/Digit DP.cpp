#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef vector <int> vi;

vector <vi> dp;

string s; int d;

// colocar algumas variações talvez, pode ser interessante
int rec(int pos, int sum, bool tight){
    if(pos == s.size()) 
        return sum == 0;

    if(dp[pos][sum]!= -1 && !tight) 
        return dp[pos][sum];
    
    int soma = 0;
    int lim = s[pos] - '0';
    if(!tight) lim = 9;

    for(int i = 0; i <= lim; i++){
        int val = rec(pos, (sum + i) % d, tight && i == lim);
        soma = (soma + val) % MOD;
    }

    if(!tight) dp[pos][sum] = soma;
    return soma;
}

void solve(){
    cin >> s;
    cin >> d;

    dp = vector <vi> (s.size(), vi(d, -1));
}

