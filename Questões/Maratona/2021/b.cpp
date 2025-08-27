// não está funcional

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;

int n;
vector <long long> fontes, cores;
multiset <vector <long long>> somas_minimas; // no vetor interno vai: valor da mult, diferença entre extremos e os dois numeros. (talvez mude)
multiset <vector <long long>> somas_maximas;

int main(){
    cin >> n;
    fontes.resize(n);
    cores.resize(n);

    for(int i = 0; i < n; ++i)
        cin >> fontes[i];

    for(int i = 0; i < n; ++i)
        cin >> cores[i];

    sort(fontes.begin(), fontes.end());
    sort(cores.begin(), cores.end());

    
    // menores somas possiveis;
    int fi = 0, ci = 0, ff = n - 1, cf = n - 1;
    for(int i = 0; i < n; ++i){
        // primeiro, verificar quais os valores das listas que serão incluidos.


        // agora, verificar se é possivel fazer alguma troca com os extremos da lista dos já incluidos e ter uma melhora
    }
    return 0;
}