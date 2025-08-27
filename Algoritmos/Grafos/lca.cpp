#include <bits/stdc++.h>
using namespace std;

int lca(vector<vector<int>>& g, int r, int v, int u) {
    int n = g.size();
    int l = ceil(log(n) / log(2));

    vector<int> pai(n, -2);
    vector<int> nivel(n);
    queue<vector<int>> fila;
    fila.push({r, -1, 1});
    while(!fila.empty()) {
        int w = fila.front()[0];
        pai[w] = fila.front()[1];
        nivel[w] = fila.front()[2];
        fila.pop();
        for (int z : g[w]) {
            if (pai[z] == -2) {
                pai[z] = w;
                fila.push({z, w, nivel[w]+1});
            }
        }
    }

    vector<vector<int>> ancestral(n, vector<int>(l, -1));
    for (int i = 0; i < n; i++) {
        ancestral[i][0] = pai[i];
    }
    for (int j = 1; j < l; j++) {
        for (int i = 0; i < n; i++) {
            if (ancestral[i][j-1] != -1) ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
        }
    }

    if (nivel[u] < nivel[v]) swap(v, u);
    for (int i = l - 1; i >= 0; i--) {
        if (nivel[u] - (1<<i) >= nivel[v]) {
            u = ancestral[u][i];
        }
    }

    if (v == u) return v;

    for (int i = l-1; i >= 0; i--) {
        if (ancestral[v][i] == -1 && ancestral[v][i] != ancestral[u][i]) {
            v = ancestral[v][i];
            u = ancestral[u][i];
        }
    }

    return pai[v];
}

int main() {
    int n, m, v, u;
    cout << "Informe o número de vértices da árvore: ";
    cin >> n;
    vector<vector<int>> g(n);
    cout << "Liste abaixo os pares de vértices que formam arestas na árvore: " << endl;
    cout << "(O grafo em questão é não direcionado)" << endl;
    for (int i = 0; i < n-1; i++) {
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    cout << "Agora informe os dois vértices para os quais você quer descobrir o respectivo menor ancestral comum: ";
    cin >> v >> u;
    v--; u--;
    cout << "O menor ancestral comum de " << v+1 << " e " << u+1 << " é " << lca(g, 0, v, u)+1 << endl;
    return 0;
}
