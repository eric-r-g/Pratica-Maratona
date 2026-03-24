#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int num_of_elements;
    vector<int> parent;
    vector<int> size;
    
    void init(int n) {
        num_of_elements = n;
        parent = vector<int>(n+1);
        size = vector<int>(n+1);
        for (int i = 1; i <= n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_set(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find_set(parent[x]);
    }
    
    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
} union_find;


///// implementação

struct query{
    int oper;
    int v, u;
};

typedef vector <vector <int>> grafo;

vector <int> ordem_inv(grafo& g, vector <query>&  operac){
    int n = g.size() - 1;

    set <pair <int, int>> remov;

    for(query q : operac){
        if(q.oper == 1){
            int a = min(q.v, q.u);
            int b = max(q.v, q.u);
            remov.insert({a, b});
        }
    }

    grafo novo(n + 1);
    for(int v = 1; v <= n; v++){
        for(int u : g[v]){
            if(remov.count({min(v, u), max(v, u)}) == 0){
                novo[v].push_back(u);
            }
        }
    }

    union_find d;
    d.init(n);

    for(int v = 1; v <= n; v++){
        for(int u : novo[v])
            if(v < u) d.union_sets(v, u);
    }

    vector <int> saida;

    for(int i = operac.size() - 1; i >= 0; i--){
        if(operac[i].oper == 1){
            d.union_sets(operac[i].v, operac[i].u);
            // guarda informaçõs adicionais de acordo com o problema
        }
        else{
            // resposta ao problema
        }

    }

    reverse(saida.begin(), saida.end());
    return saida;
}