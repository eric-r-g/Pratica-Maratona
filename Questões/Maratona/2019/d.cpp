#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> grafo;
vector <int> alturas;
priority_queue <pair <int, int>> pq;

int calcula_altura(int v){
    int tam = 1;
    for(int i = 0; i < grafo[v].size(); ++i) 
        tam = max(tam, calcula_altura(grafo[v][i]) + 1);
    
    return alturas[v] = tam;
}

void descer(int v){
    int i = 0;
    while(i < grafo[v].size()){
        if (alturas[grafo[v][i]] == alturas[v] - 1){
            descer(grafo[v][i]);
            i++;
            break;
        }
        pq.push({alturas[grafo[v][i]], grafo[v][i]});
        i++;
    }

    while(i < grafo[v].size()) pq.push({alturas[grafo[v][i]], grafo[v][i++]});
}


int main(){
	int n, k; cin >> n >> k;
    grafo = vector <vector <int>> (n + 1);
    alturas = vector <int> (n + 1);
    int entr;
    for(int i = 2; i <= n; ++i){
        cin >> entr;
        grafo[entr].push_back(i);
    }

    calcula_altura(1);

    
    pq.push({alturas[1], 1});

    int soma = 0;
    while(pq.size() && k){
        pair <int, int> p = pq.top();
        pq.pop();

        soma += p.first;
        descer(p.second);
        k--;
    }

    cout << soma << "\n";
    return 0;
} 


