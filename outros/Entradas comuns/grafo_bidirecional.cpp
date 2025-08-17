#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, v, u;
    cout << "Informe o número de vértices do grafo: ";
    cin >> n;
    vector<vector<int>> g(n);
    cout << "Informe o número de arestas do grafo: ";
    cin >> m;
    cout << "Liste abaixo os pares de vértices que formam arestas no grafo: " << endl;
    cout << "(O grafo em questão é não direcionado)" << endl;
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    return 0;
}
