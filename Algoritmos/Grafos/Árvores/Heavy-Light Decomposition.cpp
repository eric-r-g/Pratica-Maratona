#include <bits/stdc++.h>

using namespace std;

// A HLD é acompanhada de uma estrutara extra para consultas em um intervalo.
// essas estruturas no geral são ou uma seg tree ou uma arvore BIT

typedef vector <vector <int>> grafo;

struct HLD {
    vector<int> parent, depth, heavy, head, pos;
    //Seg sg; (atualizar a seg para build padrão)

    HLD(grafo& g, vector <int> val, int root = 1){
        int n = g.size() - 1;
        parent = vector <int> (n + 1);
        depth = vector <int> (n + 1);
        heavy = vector <int> (n + 1, -1);
        head = vector <int> (n + 1);
        pos = vector <int> (n + 1);
        int curr_pos = 1;
        
        parent[root] = root;
        dfs(root, g);
        decompose(root, root, g, curr_pos);

        vector <int> v_init(n);
        for(int i = 1; i <= n; i++){
            v_init[pos[i]] = val[i];
        }
        // obs, se for em cima das arestas tem que guardar a ordem
        // e uma refencia entre aresta e no filho

        // sg = Seg(v_init);
    }

    int dfs(int v, grafo& g){
        int sz = 1;
        int max_u_size = 0;
        for(int u : g[v]){
            if(u == parent[v]) continue;

            parent[u] = v;
            depth[u] = depth[v] + 1;
            int u_size = dfs(u, g);
            sz += u_size;
            if(u_size > max_u_size){
                heavy[v] = u;
                max_u_size = u_size;
            }
        }

        return sz;
    }

    void decompose(int v, int h, grafo& g, int& curr_pos){
        head[v] = h; pos[v] = curr_pos++;

        if(heavy[v] != -1){
            decompose(heavy[v], h, g, curr_pos);
        }

        for(int u : g[v]){
            if(parent[v] == u || heavy[v] == u) continue;
            decompose(u, u, g, curr_pos);
        }
    }

    void update(int v, int val){
        // seg.update(pos[v], val);
    }

    /*
    void range_update(int v, int u, int val){
        for(; head[u] != head[v]; v = parent[head[v]]){
            if(depth[head[u]] > depth[head[v]])
                swap(u, v);

            seg.update(pos[head[v]], pos[v]);
        }

        if(depth[u] > depth[v])
            swap(u, v);
        seg.update(pos[u], pos[v]);
    }
    */

    int query(int u, int v){
        int res = 0;
        for(; head[u] != head[v]; v = parent[head[v]]){
            if(depth[head[u]] > depth[head[v]])
                swap(u, v);

            int val_frag = 0; // seg.query(pos[head[v]], pos[v]);
            res = max(res, val_frag);
        }

        if(depth[u] > depth[v])
            swap(u, v);
        int val_frag = 0; // seg.query(pos[u], pos[v]);
        // obs: se for em cima da aresta, somar mais 1 ao pos[u];
        res = max(res, val_frag);

        return res;
    }
};  