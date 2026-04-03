#include <bits/stdc++.h>

using namespace std;

struct flat{
    vector <int> tin, tout;
    int tempo = 1; 
    // struct auxiliar de busca em intervalo

    flat(vector <vector <int>>& g){
        int n = g.size();
        tin.resize(n), tout.resize(n);

        dfs(1, -1, g);
        // inicializa o struct
    }

    void dfs(int v, int p, vector <vector <int>>& g){
        tin[v] = tempo++;
        for(int u : g[v])
            if(u != p) dfs(u, v, g);
        tout[v] = tempo - 1;
    }


    void update(int v, int val){
        // update struct aux 
        // update(tin[v], val);
    }

    int query(int v){
        // query struct aux
        return 0; // query(tin[v], tout[v]);
    }
};




