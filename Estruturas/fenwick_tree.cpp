#include <bits/stdc++.h>

using namespace std;

// indexado em 1
// ToDo: dá para deixar melhor visualmente
// talvez explorar também variações
struct f_tree{
    vector <int> tree;
    int n;
    int msb;

    f_tree(vector <int> &v) : tree(v.size() + 1){
        n = v.size();
        msb = 1;
        while((msb << 1) <= n) msb <<= 1;
        
        for(int i = 1; i <= n; i++){
            tree[i] += v[i - 1];
            int j = i + (i & -i);
            if (j <= n) 
                tree[j] += tree[i];
        }
    }

    int busca(int j){
        int sum = 0;
        for(; j > 0; j -= j & -j)
            sum += tree[j];

        return sum;
    }

    void add(int j, int delta){
        for(; j <= n; j += j & -j) 
            tree[j] += delta;
    }

    int lower_bound(int val){
        int pos = 0;
        int soma = 0;

        for(int i = msb; i > 0; i >>= 1){
            if (pos + i <= n and (soma + tree[pos + i] < val)){
                soma += tree[pos + i];
                pos += i;
            }
        }

        return pos + 1;
    }
};