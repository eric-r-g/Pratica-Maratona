#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ull unsigned long long

const int p1 = 91138233;
const int m = 1e9 + 7;

// aqui por ser unsigned já tem o overflow natural
const ull p2 = 1315423911;


vector <int> rolling_hash(string& s){
    int n = s.size();

    vector <int> p_pow(n);
    p_pow[0] = 1;
    for(int i = 1; i < n; i++) 
        p_pow[i] = (p_pow[i - 1] * p1) % m;

    vector <int> h(n + 1);
    h[0] = 0;
    for(int i = 1; i <= n; i++)
        h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1) * p_pow[i - 1]) % m;

    return h;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<ull, ull> mp;

ull get_hash(int x) {
    if (!mp.count(x)) {
        mp[x] = rng();
    }
    return mp[x];
}

// se quisermos menos colisões, o conjunto pode ser ordenado e resolvido com 
// rolling hash normal, porém é mais lento
ull hash_conjunto(unordered_set <int> conjunto){
    ull saida = 0;
    for(int x : conjunto)
        saida += get_hash(x);
    return saida;
}

// ToDo: hash em árvore e dag