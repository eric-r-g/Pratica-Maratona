#include <bits/stdc++.h>

using namespace std;

// constantes e variaveis padroes

const int MAXN = 1e4 + 1;
const int MAXM = 1e4 + 1;

string a, b;

// DP matriz (espaço o(n * m));

vector <vector <int>> dp_mat(MAXN, vector <int> (MAXM, 0));

void LCS_matriz(){
    for(int i = 1; i <= a.size(); ++i){
        for(int j = 1; j <= b.size(); ++j){
            if(a[i - 1] == b[j - 1]) dp_mat[i][j] = 1 + dp_mat[i - 1][j - 1];
            else dp_mat[i][j] = max(dp_mat[i -1][j], dp_mat[i][j - 1]);
        }
    }

    cout << dp_mat[a.size()][b.size()] << "\n";
}



// DP vetor (espaço (min(n, m))) 

void LCS_vetor() {
    string s1 = a, s2 = b;
    int n = s1.size(), m = s2.size();

    // garante que s1 é sempre a maior string
    if (n < m) {
        swap(s1, s2);
        swap(n, m);
    }

    // dp_vet = linha anterior, aux = linha atual
    vector<int> dp_vet(m + 1, 0), aux(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                aux[j] = 1 + dp_vet[j - 1];
            else
                aux[j] = max(dp_vet[j], aux[j - 1]);
        }
        dp_vet = aux; // avança a linha
    }

    cout << dp_vet[m] << "\n";
}


int main(){
    cin >> a >> b;
    
    LCS_vetor();

    return 0;
}