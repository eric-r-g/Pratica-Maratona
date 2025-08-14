#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

// Isso é pós-ordem mesmo?
ld pos_ordem(vector<vector<int>>& g, vector<bool>& visitado, int v, int altura, ld prob) {
    visitado[v] = true;
    int n = g[v].size();
    // Decrementa um do número de vizinhos para adquirir o número de filhos (a unidade retirada representa o pai do nó)
    if (altura > 0) n--;
    ld soma = 0;
    for (int u : g[v]) {
        if (visitado[u]) continue;
        soma += pos_ordem(g, visitado, u, altura + 1, prob / n);
    }
    if (soma == 0) return altura * prob;
    return soma;
}

int main() {
    int n, u, v;
    cin >> n;
    vector<vector<int>> g(n);
    vector<bool> visitado(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ld res = pos_ordem(g, visitado, 0, 0, 1.0);
    cout << fixed << setprecision(6) << res << endl;
    return 0;
}
