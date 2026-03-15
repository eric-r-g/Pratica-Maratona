#include <bits/stdc++.h>

using namespace std;
#define int long long

const int p = 31;
const int m = 1e9 + 9;

// ToDo: formatar melhor
vector <int> rabin_karp(string const& padrao, string const& texto){
    int sz_p = padrao.size(), sz_t = texto.size();

    vector <int> p_pow(max(sz_p, sz_t));
    p_pow[0] = 1;
    for(int i = 1; i < p_pow.size(); i++) 
        p_pow[i] = (p_pow[i - 1] * p) % m;

    int val_padrao = 0;
    for(int i = 0; i < sz_p; i++)
        val_padrao = (val_padrao + p_pow[i] * (padrao[i] - 'a' + 1)) % m;

    vector <int> h(sz_t + 1);
    h[0] = 0;
    for(int i = 0; i < sz_t; i++)
        h[i + 1] = (h[i] + p_pow[i] * (texto[i] - 'a' + 1)) % m;

    vector <int> ocorrencias;
    for(int i = 0; i + sz_p < sz_t + 1; i++){
        int val_sub = (h[i + sz_p] - h[i] + m) % m;
        if(val_sub == (val_padrao * p_pow[i]) % m) 
            ocorrencias.push_back(i);
    }

    return ocorrencias;
}

const int p = 31;
const int m = 1e9 + 9;

// achar todas as substrings palindromicas
vector <pair <int, int>> substrings_palin(string& s){
    string r;
    copy(s.begin(), s.end(), r.begin());
    reverse(r.begin(), r.end());

    int sz = s.size();

    vector <int> p_pow(sz);
    p_pow[0] = 1;
    for(int i = 1; i < sz; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector <int> hs(sz + 1), hr(sz + 1);
    hs[0] = 0, hr[0] = 0;
    for(int i = 0; i < sz; i++){
        hs[i + 1] = (hs[i] + p_pow[i] * (s[i] - 'a' + 1)) % m;
        hr[i + 1] = (hr[i] + p_pow[i] * (r[i] - 'a' + 1)) % m;
    } 

    vector <pair <int, int>> ocorr;


    return ocorr;
}