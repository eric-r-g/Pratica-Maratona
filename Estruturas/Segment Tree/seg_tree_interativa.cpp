#include <bits/stdc++.h>

using namespace std;

struct seg_tree_inter{
    int n;
    vector <int> t;

    seg_tree_inter(vector <int>& v){
        n = v.size();
        t.resize(2 * n);
        for(int i = 0; i < n; i++)
            t[n + i] = v[i];

        for(int i = n - 1; i > 0; i--)
            t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    int query(int l, int r){
        int res = 0;

        for(l += n, r += n; l <= r; l /= 2, r /= 2){
            if(l % 2 == 1) res = max(res, t[l++]);
            if(r % 2 == 0) res = max(res, t[r--]);
        }

        return res;
    }

    void update(int pos, int val){
        pos += n;
        t[pos] = val;

        for(pos /= 2; pos > 0; pos /= 2)
            t[pos] = max(t[2 * pos], t[2 * pos + 1]);
    }
};