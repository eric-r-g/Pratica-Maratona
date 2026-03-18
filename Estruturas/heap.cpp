#include <bits/stdc++.h>

using namespace std;

// ToDo: não estou satisfeito com esse modelo, 
// verificar depois como melhorar.

struct heap {
    vector <int> t;
    int n;

    heap (int MAXN) : t(MAXN), n(0) {};

    void insert(int val){
        n++;
        t[n] = val;
        heapfy_up(n);
    }

    int top(){
        return t[1];
    }

    void pop(){
        if(n == 0) return; // impossivel;
        t[1] = t[n];
        n--;
        heapfy_down(1);
    }

    void heapfy_up(int pos){
        while(pos != 1 && t[pos / 2] < t[pos]){
            std::swap(t[pos], t[pos / 2]);
            pos /= 2;
        }
    }

    void heapfy_down(int pos){
        while(true){
            int big = pos;
            int l = 2 * pos;
            int r = 2 * pos + 1;

            if(l <= n && t[l] > t[big]) big = l;
            if(r <= n && t[r] > t[big]) big = r;

            if(big == pos) break;
            
            std::swap(t[pos], t[big]);
            pos = big;
        }
    }
};