#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, v, u;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> grau(n);
    queue<int> fila;
    vector<int> lista;
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        grau[u]++;
    }
    for (int i = 0; i < n; i++) {
        if (grau[i] == 0) fila.push(i);
    }
    while (!fila.empty()) {
        v = fila.front();
        fila.pop();
        lista.push_back(v);
        for (int u : g[v]) {
            grau[u]--;
            if (grau[u] == 0) fila.push(u);
        }
    }
    if (lista.size() < n) {
        cout << "Impossível realizar as operações na ordem exigida!" << endl;
    } else {
        cout << "A ordem é a seguinte:" << endl;
        for (int i = 0; i < n; i++) {
            cout << lista[i]+1 << endl;
        }
    }
    return 0;
}
