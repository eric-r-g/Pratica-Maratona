#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 1;

int parent[MAXN], sz[MAXN];
int n;

void inicializar(int n){
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

int pai(int x){
    if (parent[x] == x) return x;
    else return parent[x] = pai(parent[x]);
}

void merge(int x, int y){
    x = pai(x);
    y = pai(y);

    if(sz[x] > sz[y]){
        parent[y] = parent[x];
        sz[x] += sz[y];
    } else {
        parent[x] = parent[y];
        sz[y] += sz[x];
    }
}

int main(){

}