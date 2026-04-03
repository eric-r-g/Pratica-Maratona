#include <bits/stdc++.h>

using namespace std;

struct flat{
    vector <int> tin, tout;
    int tempo = 1; 
    vector <vector <int>> tin_depth;

    // caso não tenha updates
    vector <vector <int>> prefix;
    // se não
    // vector <f_tree> bit;

    flat(vector <vector <int>>& g){
        int n = g.size();
        tin.resize(n), tout.resize(n);
        tin_depth.resize(n), prefix.resize(n);

        dfs(1, 0, 1, g);
    }

    void dfs(int v, int p, int d, vector <vector <int>>& g){
        tin[v] = tempo++;
        
        // ajuste dos tempos tin
        tin_depth[d].push_back(tin[v]);
        

        // ajuste da soma prefixa
        if(prefix[d].empty()) prefix[d].push_back(0); // elemento neutro
        prefix[d].push_back(prefix[d].back());
        // calcula o prefixo

        for(int u : g[v])
            if(p != u) dfs(u, v, d + 1, g);
        tout[v] = tempo - 1;
    }

    void update(int v, int val){
        // somente valida para fenwick tree
    }

    int query(int v, int h){
        if (h >= tin_depth.size() || tin_depth[h].empty()) return 0; // retorno de caso não tenha nós

        int ini = lower_bound(tin_depth[h].begin(), tin_depth[h].end(), tin[v]) - tin_depth[h].begin();
        int end = upper_bound(tin_depth[h].begin(), tin_depth[h].end(), tout[v]) - tin_depth[h].begin();

        int saida = 0;
        // calcula o intervalo

        return saida;
    }
};



