#include <bits/stdc++.h>

using namespace std;

// ToDo: formatação

/////////// seg tree normal dinamica 
struct no {
    int val;
    no* l;
    no* r;

    no (int v = 0) : val(v), l(nullptr), r(nullptr) {}
};

struct seg_tree {
    no * raiz;
    int sz;

    seg_tree(int n) {
        sz = n;
        raiz = nullptr;
    }

    int query(int l, int r){
        return query(raiz, 1, sz, l, r);
    }

    int query(no * v, int tl, int tr, int l, int r){
        if (l > r || !v) return 0;

        if(l == tl && r == tr) return v -> val;
        int med = (tl + tr) / 2;
        return query(v -> l, tl, med, l, min(r, med))
             + query(v -> r, med + 1, tr, max(l, med + 1), r);

    }

    void update(int pos, int val){
        update(raiz, 1, sz, pos, val);
    }

    void update(no * &v, int tl, int tr, int pos, int val){
        if(!v) v = new no();

        if(tl == tr) v -> val = val;
        else {
            int med = (tl + tr) / 2;
            if (pos <= med) update(v -> l, tl, med, pos, val);
            else update(v -> r, med + 1, tr, pos , val);

            int esq = 0;
            if(v -> l) esq = v -> l -> val;
            int dir = 0;
            if(v -> r) dir = v -> r -> val;
            v -> val = esq + dir;
        }
    }
};


////////// seg tree lazy dinamica

struct no {
    int val;
    int lazy; 

    no* l;
    no* r;

    no (int v = 0, int lz = 0) : val(v), lazy(lz), l(nullptr), r(nullptr) {}
};

struct seg_tree {
    no * raiz;
    int sz;

    seg_tree(int n) {
        sz = n;
        raiz = nullptr;
    }

    // assume que o nó existe
    void push(no * v, int tl, int tr){
        if(v -> lazy != 0){
            v -> val += (tr - tl + 1) * (v -> lazy); 

            if(tl != tr){
                if(v -> l == nullptr) v -> l = new no();
                v -> l -> lazy += v -> lazy;
                if(v -> r == nullptr) v -> r = new no();
                v -> r -> lazy += v -> lazy;
            }

            v -> lazy = 0;
        }
    }

    int query(int l, int r){
        return query(raiz, 1, sz, l, r);
    }

    int query(no * v, int tl, int tr, int l, int r){
        if(l > r || !v) return 0;

        push(v, tl, tr);

        if(tl == l && tr == r) 
            return v -> val;

        int med = (tl + tr) / 2;

        return query(v -> l, tl, med, l, min(r, med))
             + query(v -> r, med + 1, tr, max(l, med + 1), r);
    }

    void update(int l, int r, int val){
        update(raiz, 1, sz, l, r, val);
    }

    void update(no * &v, int tl, int tr, int l, int r, int val){
        if(l > r) return;
        if(v == nullptr) v = new no();
        push(v, tl, tr);

        if(tl == l && tr == r){
            v -> lazy += val;
            push(v, tl, tr);
            return;
        }

        int med = (tl + tr) / 2;
        update(v -> l, tl, med, l, min(r, med), val);
        update(v -> r, med + 1, tr, max(l, med + 1), r, val);
        
        int esq = 0;
        if(v -> l) esq = v -> l -> val;
        int dir = 0;
        if(v -> r) dir = v -> r -> val;
        v -> val = esq + dir;
    }
};