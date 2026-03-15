#include <bits/stdc++.h>

using namespace std;

vector <int> kmp(string& s){
    int n = s.size();
    vector <int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];

        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        } 
        
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}


// constante que não aparece nos textos
const char IMP = '#';

// encontrar todas as ocorrencias
vector <int> kmp_ocorr(string& a, string& b){
    int n = a.size(), m = b.size();
    
    string v = a + IMP + b;
    vector <int> pi(n + m + 1);

    vector <int> ocorr;
    for(int i = 1; i <= n + m; i++){
        int j = pi[i - 1];
        while(j > 0 && v[i] != v[j]){
            j = pi[j - 1];
        } if (v[i] == v[j]) j++;
        pi[i] = j;
        if(j == n){
            ocorr.push_back(i - 2 * n);
        }
    }

    return ocorr;
}