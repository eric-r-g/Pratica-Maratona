#include <bits/stdc++.h>

using namespace std;

const int INF = 2;

const int N = 100;
int gauss(int n, int m, vector <bitset<N>>& mat, bitset <N>& saida){
    vector <int> pivo(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        // escolha do pivo
        int sel = row;
        for(int i = row; i < n; i++)
            if(mat[i][col]){
                sel = i;
                break;
            }
        
        // pivo 0
        if(!mat[sel][col]) continue;
        pivo[col] = row;
        swap(mat[row], mat[sel]);

        // diagonaliza
        for (int i=0; i<n; ++i)
            if (i != row && mat[i][col])
                mat[i] ^= mat[row];
        ++row;
    }

    for (int i=0; i<m; ++i)
        if (pivo[i] != -1)
            saida[i] = mat[pivo[i]][m];
    
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum ^= (saida[j] & mat[i][j]);
        if (sum ^ mat[i][m])
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (pivo[i] == -1)
            return INF;
    return 1;
}

