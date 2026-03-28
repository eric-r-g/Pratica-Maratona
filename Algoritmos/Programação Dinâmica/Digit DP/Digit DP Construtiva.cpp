#include <bits/stdc++.h>

using namespace std;

int lim = 18;

typedef vector <int> vi;
vector <vector <vi>> dp;

string s;
int rec(int pos, int last, bool started){
    if(pos == lim)
        if(started) return 1;
        else return 0;

    if(dp[pos][last][started] != -1)
        return dp[pos][last][started];

    int soma = 0;
    for(int i = 0; i <= 9; i++){
        // verifica condições
        soma += rec(pos + 1, i, started || (i != 0));
    }

    return dp[pos][last][started] = soma;
}

int query(int x){
    int saida = 0, last = 0;
    bool started = false;
    for(int i = 0; i < lim; i++){
        for(int d = 0; d <= 9; d++){
            // verifica as condições

            int cnt = rec(i + 1, d, started || (d != 0));
            if(cnt >= x){
                saida = saida * 10 + d;
                started |= d != 0;
                last = d;
                break;
            } else x -= cnt;
        }
    }

    return saida;
}

vector <int> dp_digit_construtiva(vector <int>& consultas){
    dp = vector <vector <vi>> (lim, vector <vi> (10, vi (2, -1)));

    vector <int> saida;
    for(int x : consultas)
        saida.push_back(query(x));
    

    return saida;
}

