#include <iostream>


using namespace std;
int main()
{
    // receber o número de sacola, as sacolas, e a soma total (que já foi chamada de meta)
    int n, meta = 0, l_sac[100];
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> l_sac[i];
        meta += l_sac[i];
    }

    
    // determinar se a meta é um número possivel (par) e se sim, dividir a soma total para obte-la
    if (meta % 2 == 1){
        cout << "-1" << endl;
        return 0;
    }
    meta /= 2;

    /* 
    aqui eu inicei uma serie de preparativos para a proxima parte, são eles:
      - soma_poss que é uma lista de boleanos (serve para a programção dinamica), e com o 0 ja possivel.
      - num_necessario em que utilizando uma técnica de bitmask, eu determino para as somas possiveis quais
        foram as sacolas necessarias para chegar naquela soma (obs: eu quebrei em duas listas para ao invés de
        ser numeros de 2⁹⁹, utilizo 2 numeros de 2⁵⁵).
      - e por fim, pot_de_2 serve apenas para ter as potencias de 2 já guardadas.
    */
    bool soma_poss [5001] = {};
    soma_poss[0] = true;
    unsigned long long num_necessario[2][5001];
    unsigned long long pot_de_2[50];
    pot_de_2[0] = 1;
    for(int i = 1;  i < 50; ++i){
        pot_de_2[i] = 2 * pot_de_2[i - 1];
    }

    
    for (int i = 0; i < n; ++i){
        for(int j = meta - 1; j > -1; --j){
            int pos = j + l_sac[i];

            // aqui estamos operando a parte da programação dinamica. Se uma soma na posição j já foi alcançada,
            // e se a soma mais o valor da sacola ainda não foi, eu realizo todos os processos
            if (soma_poss[j] and pos < meta and !soma_poss[pos]){
                soma_poss[pos] = true;

                // parte do bitmask para sabermos quais sacolas foram necessárias.
                num_necessario[0][pos] = num_necessario[0][j];
                num_necessario[1][pos] = num_necessario[1][j];
                if (i < 50) num_necessario[0][pos] |= pot_de_2[i];
                else num_necessario[0][pos] |= pot_de_2[i - 50];
            }
        }
        
        if (soma_poss[meta]) break;
    }
    
    if (!soma_poss[meta]) cout << -1 << endl;
    else{
        cout << num_necessario[0][meta];
    }
    
    // o problema ainda não foi terminado, só sabemos se a soma é possivel e se sim, quais as sacolas necessarias 
    // para chegar nesssa soma (as que não foram escolhidas vão servir para a outra pessoa chegar no mesmo valor).
    return 0;
}
