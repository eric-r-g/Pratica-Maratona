#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 2;

int fast_pow(int base, int ind = MOD - 2){
    int acum = 1;
    while(ind > 0){
        if (ind & 1) acum = (acum * base) % MOD;
        base = (base * base) % MOD;
        ind >>= 1;
    }
    return acum;
}

int gauss(vector <vector <int>> mat, vector <int>& saida){
    int n = mat.size();
    int m = mat[0].size() - 1;

    vector <int> pivo(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        // escolha do pivo
        int sel = row;
        for(int i = row; i < n; i++)
            if(mat[i][col] != 0)
                sel = i;
        
        // pivo = 0: soluçãos infinitas ou nenhuma
        if(mat[sel][col] == 0) continue;
        for (int i=col; i<=m; ++i)
            swap (mat[sel][i], mat[row][i]);
        pivo[col] = row;

        // aplica o valor
        for(int i = 0; i < n; i++){
            if(i == row) continue;
            int c = (mat[i][col] * fast_pow(mat[row][col])) % MOD;
            for (int j=col; j<=m; ++j)
                mat[i][j] = (mat[i][j] - (mat[row][j] * c) % MOD + MOD) % MOD;
        }

        ++row;
    }

    saida.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (pivo[i] != -1)
            saida[i] = (mat[pivo[i]][m] * fast_pow(mat[pivo[i]][i])) % MOD;
    
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + (saida[j] * mat[i][j]) % MOD) % MOD;
        if ((sum - mat[i][m] + MOD) % MOD != 0)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (pivo[i] == -1)
            return INF;
    return 1;
}

