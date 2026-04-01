#include <bits/stdc++.h>

using namespace std;

const int sz = 317;

struct update{
    int tipo;
    int v, u;
};

vector <update> batch;

// reconstroi o grafo / estrutura baseado nos updates
void rebuild(){
    for(update u : batch){
        // aplica o update
    }
    batch.clear();
}

int query(){
    int saida = 0;

    // faz o calculo normal

    for(update u : batch){
        // aplica o update pro calculo
    }
    return saida;
}

void solve(){
    int n, q; cin >> n >> q;
    // recebe os valores
    rebuild();

    while(q--){
        int type; cin >> type;

        // caso update
        if(type == 1) {
            // atualiza os dados para o leve
            int v, u; cin >> v >> u;
            batch.push_back({type, v, u});

            if(batch.size() == sz) update();
        }

        // caso querie
        if(type == 2) {
            cout << query() << "\n";
        }
    }
}