#include <bits/stdc++.h>

using namespace std;

// constantes e variaveis padroes

const int MAXN = 101;  
const int MAXC = 100001;
const long long inf = 0x3f3f3f3f3f3f3f3f; // ~= 10^18

int n, c;
int valores[MAXN], pesos[MAXN];

// DP-Capacidade FORMA
// valido para capacidade menores

vector<long long> dp(MAXC+1, -inf);

void solucao_dinamica_cap(){
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = pesos[i]; j <= c; ++j){
            dp[j] = max(dp[j], dp[j - pesos[i]] + valores[i]);
        }
    }

    cout << dp[c] << "\n";
}

// DP-valores FORMA
// valido para capacidade menores

const int MAXVAL = 100000;

vector<long long> dp(MAXVAL+1, inf);

void solucao_dinamica_val(){
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int v = valores[i]; v <= MAXVAL; ++v){
            dp[v] = min(dp[v], dp[v - valores[i]] + pesos[i]);
        }
    }

    long long melhor_valor = 0;
    for(int v = MAXVAL; v >= 0; --v){
        if(dp[v] <= c){ // peso permitido
            melhor_valor = v;
            break;
        }
    }
    cout << melhor_valor << "\n";
}

int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; ++i){
        cin >> pesos[i] >> valores[i];
    }

    return 0;
}