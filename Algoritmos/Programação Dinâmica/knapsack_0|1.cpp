#include <bits/stdc++.h>

using namespace std;

typedef vector <pair <long long, long long>> vpll;

// constantes e variaveis padroes

const int MAXN = 101;  
const int MAXC = 100001;
const long long inf = 0x3f3f3f3f3f3f3f3f; // ~= 10^18


int n, c;
int valores[MAXN], pesos[MAXN];

// DP-Capacidade FORMA
// valido para capacidade menores

vector<long long> dp(c+1, -inf);

void solucao_dinamica_cap(){
    dp[0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = c; j >= pesos[i]; --j){
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
        for(int v = MAXVAL; v >= valores[i]; --v){
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

// EA FORMA
// valido para capacidade e valores possiveis maior e numero de elementos pequenos

vpll EA;

void solucao_estados_alcancaveis(){
    EA = {{0, 0}};

    for(int i = 1; i <= n; ++i){
        vpll novos;
        novos.reserve(EA.size());

        for(auto [v,p] : EA){
            long long nv = v + valores[i];
            long long np = p + pesos[i];
            if(np <= c) novos.push_back({nv,np});
        }

        vpll merged;
        merged.reserve(EA.size() + novos.size());

        int a=0, b=0;
        while(a < (int)EA.size() || b < (int)novos.size()){
            pair<long long,long long> cand;
            if(b == (int)novos.size() || (a < (int)EA.size() && EA[a].second < novos[b].second))
                cand = EA[a++];
            else if(a == (int)EA.size() || (b < (int)novos.size() && novos[b].second < EA[a].second))
                cand = novos[b++];
            else {
                // pesos iguais: fica o de maior valor
                cand = (EA[a].first >= novos[b].first) ? EA[a] : novos[b];
                a++; b++;
            }

            // pruning em linha: só mantém se valor é maior que último
            if(merged.empty() || cand.first > merged.back().first)
                merged.push_back(cand);
        }

        EA.swap(merged);
    }

    cout << EA.back().first << "\n";
}


int main(){
    cin >> n >> c;
    for(int i = 1; i <= n; ++i){
        cin >> pesos[i] >> valores[i];
    }

    return 0;
}