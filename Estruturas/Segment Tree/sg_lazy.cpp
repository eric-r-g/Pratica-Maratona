#include <bits/stdc++.h>

using namespace std;

// ToDo: formatação
struct seg_tree_lazy {
    vector <int> t;
    vector <int> lazy; // vetor com as mudanças não aplicadas
    int sz;

    seg_tree_lazy (vector <int> &v) : sz(v.size()), t(4 * (v.size())), lazy(4 * (v.size())) {
        build(v, 1, 1, sz);
    }

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

    // coração da seg tree
    void push(int v, int tl, int tr){
        if(lazy[v] != 0){
            // depende da operação
            t[v] += (tr - tl + 1) * lazy[v];

            if(tl != tr){
                lazy[2 * v] += lazy[v];
                lazy[2 * v + 1] += lazy[v];
            }

            lazy[v] = 0;
        }
    }

    // l -> extremidade esquerda da busca
    // r -> extremidade direita da busca
    int query(int l, int r){
        return query(1, l, r, 1, sz);
    }

    int query(int v, int l, int r, int tl, int tr){
        if(l > r) return 0;

        push(v, tl, tr); // aplica as mudanças antes de mais nada

        if(l == tl && r == tr) return t[v];

        int med = (tl + tr) / 2;
        return query(2 * v, l, min(r, med), tl, med) 
                + query(2 * v + 1, max(l, med + 1), r, med + 1, tr);
    }

    void update(int l, int r, int val){
        update(1, 1, sz, l, r, val);
    }

    void update(int v, int tl, int tr, int l, int r, int val){
        push(v, tl, tr);

        if(l > r) return;

        if(tl == l && tr == r){
            lazy[v] += val;
            push(v, tl, tr);
            return;
        }

        int med = (tl + tr) / 2;
        update(2 * v, tl, med, l, min(r, med), val);
        update(2 * v + 1, med + 1, tr, max(l, med + 1), r, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
};