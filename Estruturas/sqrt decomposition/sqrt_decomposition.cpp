#include <bits/stdc++.h>

using namespace std;

// adaptar as necessidades
const int sz = 317;

struct sqrt_decomposition{
    vector <int> a, b;
    int n;

    sqrt_decomposition(vector <int>& v){
        a = v;
        n  = v.size();
        b.resize(n / sz + 1);

        for(int i = 0; i < n; i++)
            b[i / sz] += a[i];
    }

    void update(int pos, int val){
        b[pos / sz] -= a[pos];
        a[pos] = val;
        b[pos / sz] += a[pos];
    }

    int query(int l, int r){
        // exemplo de consulta

        int sum = 0;
        for(int i = l; i <= r;){
            // todo bloco pertence
            if(i % sz == 0 && i + sz - 1 <= r){
                sum += b[i / sz];
                i += sz;
            }
            else {
                sum += a[i];
                i++;
            }
        }

        return sum;
    }
};