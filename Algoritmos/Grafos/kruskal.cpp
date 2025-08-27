#include <bits/stdc++.h>
using namespace std;

vector<int> pai;
vector<int> prof;

int find(int x) {
    if (pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (prof[rx] < prof[ry]) pai[rx] = ry;
    else if (prof[rx] > prof[ry]) pai[ry] = rx;
    else {
        pai[rx] = ry;
        prof[ry]++;
    }
}

typedef struct t_aresta {
    int v, u;
    int peso;
} t_aresta;

bool comp(t_aresta a, t_aresta b) { return a.peso < b.peso; }

int main() {
    int n, m, v, u, w, a, b;
    cin >> n;
    cin >> m;
    vector<t_aresta> g(m);
    pai = vector<int>(n);
    prof = vector<int>(n);
    vector<t_aresta> mst;
    for (int i = 0; i < n; i++) {
        pai[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        v--; u--;
        g[i].v = v;
        g[i].u = u;
        g[i].peso = w;
    }
    sort(g.begin(), g.end(), comp);
    for (int i = 0; i < m; i++) {
        if (find(g[i].v) != find(g[i].u)) {
            mst.push_back(g[i]);
            join(g[i].v, g[i].u);
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << mst[i].v+1 << " -> " << mst[i].u+1 << endl;
    }
    return 0;
}
