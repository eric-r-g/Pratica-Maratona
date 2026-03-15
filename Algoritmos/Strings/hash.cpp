#include <bits/stdc++.h>

using namespace std;
#define int long long


// ToDo: formatar melhor
int main(){
    string s; cin >> s;
    int n = s.size();

    // constantes p e m
    int p = 31;
    int m = 1e9 + 7;

    vector <int> p_pow(n);
    p_pow[0] = 1;
    for(int i = 1; i < n; i++) 
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector <int> h(n + 1);
    h[0] = 0;
    for(int i = 1; i <= n; i++)
        h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * p_pow[i - 1]) % m;

    return 0;
}