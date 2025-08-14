// A lógica está incorreta

#include <bits/stdc++.h>
using namespace std;

typedef struct camara {
    vector<int> itens;
    int soma;
} camara;

int main() {
    int c, s, p, ind_menor, soma_menor, set = 1;
    double media_camaras, desvio_medio;
    while(cin >> c >> s) {
        media_camaras = desvio_medio = 0.0;
        if (set > 1) cout << endl;
        vector<camara> camaras(c);
        vector<int> specimens(s);
        for (int i = 0; i < s; i++) {
            cin >> p;
            specimens.push_back(p);
        }
        sort(specimens.begin(), specimens.end(), greater<int>());
        for (int i = 0; i < s; i++) {
            ind_menor = 0;
            soma_menor = 9999999;
            p = specimens[i];
            for (int j = 0; j < c; j++) {
                if (camaras[j].soma < soma_menor) {
                    soma_menor = camaras[j].soma;
                    ind_menor = j;
                }
            }
            camaras[ind_menor].itens.push_back(p);
            camaras[ind_menor].soma += p;
        }
        cout << "Set #" << set << endl;
        for (int i = 0; i < c; i++) {
            media_camaras += camaras[i].soma;

            cout << i << ": ";
            for (int j = 0; j < camaras[i].itens.size(); j++) {
                cout << camaras[i].itens[j];
                if (j != camaras[i].itens.size() - 1) cout << " ";
            }
            cout << endl;
        }
        media_camaras = (media_camaras / (double) c);
        for (int i = 0; i < c; i++) {
            desvio_medio += (abs(media_camaras - camaras[i].soma));
        }
        cout << "IMBALANCE = " << desvio_medio << endl;
        set++;
    }
    return 0;
}
