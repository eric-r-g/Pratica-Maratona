#include <bits/stdc++.h>

using namespace std;

// ToDo: formatar melhor
struct seg_tree{
    // t -> vetor "arvore", sz -> tamanho
    vector <int> t;
    int sz;

    seg_tree (vector <int> &v) : sz(v.size()), t(4 * (v.size())){
        build(v, 1, 1, sz);
    }

    // v -> representa o vertice, a posição atual no t
    // tl -> extremidade esquerda do vertice atual
    // tr -> extremidade direita do vertice atual
    void build(vector <int> &a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl - 1];
        } else {
            int med = (tl + tr) / 2;
            build(a, 2 * v, tl, med);
            build(a, 2 * v + 1, med + 1, tr);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    // l -> extremidade esquerda da busca
    // r -> extremidade direita da busca
    int query(int l, int r){
        return query(1 , 1, sz, l, r);
    }

    int query(int v, int tl, int tr, int l, int r){
        if(l > r) return 0;
        if(l == tl && r == tr) return t[v];
        int med = (tl + tr) / 2;
        
        return query(2 * v, tl, med, l, min(r, med))
             + query(2 * v + 1, med + 1, tr, max(l, med + 1), r);
    }

    void update(int pos, int n_val){
        update(1, 1, sz, pos, n_val);
    }

    void update(int v, int tl, int tr, int pos, int n_val){
        if(tl == tr) t[v] = n_val;
        else {
            int med = (tl + tr) / 2;
            if(pos <= med) update(2 * v, tl, med, pos, n_val);
            else update(2 * v + 1, med + 1, tr, pos, n_val);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
};