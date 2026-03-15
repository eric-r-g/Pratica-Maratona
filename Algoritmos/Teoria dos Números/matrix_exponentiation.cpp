#include <bits/stdc++.h>

using namespace std;


struct matr {
    vector <vector <int>> m;
    int n;

    matr (int n) : 
        n(n), m(n, vector<int> (n)){}

    matr operator* (const matr& other) const {
        matr novo(n);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                int v = m[i][k];
                if (v == 0) continue;
                for (int j = 0; j < n; ++j) {
                    novo.m[i][j] += v * other.m[k][j];
                }
            }
        }

        return novo;
    }

    static matr identidade(int n){
        matr novo(n);
        for(int i = 0; i < n; i++) novo.m[i][i] = 1;
        return novo;
    }
};

matr fast_pow_matr(matr base, int ind){
    matr acum = matr::identidade(base.n);
    while(ind > 0){
        if (ind & 1) acum = acum * base;
        base = base * base;
        ind >>= 1;
    }
    return acum;
}