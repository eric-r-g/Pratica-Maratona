#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000001;
int v[MAXN];

int main(){
    int n; cin >> n;

    int cont = 1;
    int a, b;
    while(n){
        for(int i = 1; i <= n; ++i){
            cin >> a >> b;
            v[i] = a - b;
        }

        int ini_f, ini = 1, maior = 0, soma = 0, dif_f = 0, dif = 0;
        for(int i = 1; i <= n; ++i){
            dif += 1;
            soma += v[i];
            if (soma < 0){
                ini = i + 1;
                soma = 0;
                dif = 0;
            } else if (soma > maior){
                ini_f = ini;
                maior = soma;
                dif_f = dif;
            } else if (soma == maior && dif > dif_f){
                ini_f = ini;
                dif_f = dif;
            }
        }

        if (soma > maior){
            ini_f = ini;
            maior = soma;
            dif_f = dif;
        } else if (soma == maior && dif > dif_f){
            ini_f = ini;
            dif_f = dif;
        }
        
        cout << "Teste " << cont++ << "\n";
        if(!maior) cout << "nenhum\n\n";
        else cout << ini_f << " " << ini_f + dif_f - 1 << "\n\n";
        cin >> n;
    }
    return 0;
}


