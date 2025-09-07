#include <bits/stdc++.h>

using namespace std;
typedef pair <int, long> pil;

vector <pil> arvore; // pai, valor proprio
vector <pil> caminho; // numero de fotos tiradas, ultimo valor usado

pil caminhar(int i){
    if(caminho[i].first != 0) return caminho[i];

    pil pai = caminhar(arvore[i].first);
    pil par_atual = {pai.first, pai.second};
}

int main(){
    int n;
    cin >> n;

    arvore.reserve(n + 1);
    caminho.reserve(n + 1);

    arvore[1].first = -1;
    for(int i = 2; i <= n; ++i) cin >> arvore[i].first;
    for(int i = 1; i <= n; ++i) cin >> arvore[i].second;

    for(int i = 1; i <= n; ++i) caminho[i].first = 0;

    caminho[1].first = 1;
    caminho[1].second = arvore[1].second;
}