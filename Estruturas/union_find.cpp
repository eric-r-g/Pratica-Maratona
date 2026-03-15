#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int num_of_elements;
    vector<int> parent;
    vector<int> size;
    
    void init(int n) {
        num_of_elements = n;
        parent = vector<int>(n+1);
        size = vector<int>(n+1);
        for (int i = 1; i <= n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_set(int x) {
        if (parent[x] == x) return x;
        else return parent[x] = find_set(parent[x]);
    }
    
    void union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            if (size[x] < size[y])
                swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }
} union_find;