#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const int INF = 2;

int gauss(vector <vector <double>> mat, vector <double>& saida){
    int n = mat.size();
    int m = mat[0].size() - 1;

    vector <int> pivo(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        // escolha do pivo
        int sel = row;
        for(int i = row; i < n; i++)
            if(abs(mat[i][col]) > abs(mat[sel][col]))
                sel = i;
        
        // pivo = 0: soluçãos infinitas ou nenhuma
        if(abs(mat[sel][col]) < eps) continue;
        for (int i=col; i<=m; ++i)
            swap (mat[sel][i], mat[row][i]);
        pivo[col] = row;

        // aplica o valor
        for(int i = 0; i < n; i++){
            if(i == row) continue;
            double c = mat[i][col] / mat[row][col];
            for (int j=col; j<=m; ++j)
                mat[i][j] -= mat[row][j] * c;
        }

        ++row;
    }

    saida.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (pivo[i] != -1)
            saida[i] = mat[pivo[i]][m] / mat[pivo[i]][i];
    
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += saida[j] * mat[i][j];
        if (abs (sum - mat[i][m]) > eps)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (pivo[i] == -1)
            return INF;
    return 1;
}

