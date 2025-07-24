#include <bits/stdc++.h>

using namespace std;

int main(){    
    vector <bool> v;

    // considerando n >= 2
    int n; 
    cin >> n;

    /* 
        todos começam como primos
        e n++ para facilitar na hora de marcar e verificar os números
    */

    v.assign(++n, 1); 

    // marca todos os pares maiores que 2 como não pares
    for (int i = 4; i <= n; i += 2){
        v[i] = 0;
    }
    
    v[0] = 0;
    v[1] = 0;

    // começa a partir do 3
    int k = 3;
    while(k * k <= n){
        // podemos olhar no k² pois os anterios a esse já vão está marcados
        int passo = 2 * k;
        int atual = k * k;
        while (atual <= n) {
            v[atual] = 0;
            atual += passo;
        }

        // procurar o proximo k primo
        k += 1;
        while(!v[k]) k++;
    }

    int q;
    cin >> q;
    while(q--){
        int entr;
        cin >> entr;
        cout << v[entr] << endl;
    }
    return 0;
}