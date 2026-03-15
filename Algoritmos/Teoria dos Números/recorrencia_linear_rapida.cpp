#include <bits/stdc++.h>

#define int long long

using namespace std;

//ToDo: dá uma revisada na formatação e talvez muda de lugar?

const int MOD = 1e9 + 7;
int sz = 2; // tamanho da sua recorrencia

struct matr {
    vector <vector <int>> m;
    int n;

    matr (int n) :
        n(n), m(n, vector <int> (n)){}

    matr operator* (const matr& other) const {
        matr novo(n);
        for(int i = 0; i < n; ++i){
            for (int k = 0; k < n; ++k){
                int v = m[i][k];
                if(v == 0) continue;
                for(int j = 0; j < n; ++j){
                    novo.m[i][j] = (novo.m[i][j] + v * other.m[k][j]) % MOD;
                }
            }
        }

        return novo;
    }

    static matr identidade(int n){
        matr novo(n);
        for(int i = 0; i < n; i++)
            novo.m[i][i] = 1;
        return novo;
    }
};

vector <int> operator* (const matr& b, const vector <int>& a) {
    int n = a.size();
    vector <int> novo(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            novo[i] = (novo[i] + b.m[i][j] * a[j]) % MOD;
        }
    }

    return novo;
}

matr fast_pow(matr base, int ind){
    matr acum = matr::identidade(base.n);
    while(ind > 0){
        if(ind & 1) acum = acum * base;
        base = base * base;
        ind >>= 1;
    }

    return acum;
}

// dado uma recorrencia já estabelecida
vector <int> recorrencia(const vector <int>& entr, const matr& transf, int n){
    return fast_pow(transf, n) * entr;
}

int32_t main(){
    int n; cin >> n;
    matr transf(sz);
    transf.m[0][0] = 0, transf.m[0][1] = 1;
    transf.m[1][0] = 1, transf.m[1][1] = 1;

    vector <int> entr = {0, 1};
    vector <int> saida = recorrencia(entr, transf, n);

    cout << saida[0] << "\n";
}