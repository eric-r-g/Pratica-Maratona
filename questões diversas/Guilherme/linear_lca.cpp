#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int lca(vector<vector<int>>& g, vector<int>& pai, int v, int w) {
    int n = pai.size();
    int raiz, u, altura_atual;
    // Ancestral do v, ancestral do w
    int av, aw;
    static vector<int> altura;
    queue<pii> fila;
    if (n == 0) return 0;
    if (altura.size() == 0) {
        altura = vector<int>(n);
        for (int i = 0; i < n; i++) {
            if (pai[i] == -1) {
                raiz = i;
                break;
            }
        }
        fila.push({raiz, 0});
        while(!fila.empty()) {
            u = fila.front().first;
            altura_atual = fila.front().second;
            fila.pop();
            altura[u] = altura_atual;
            for (int w : g[u]) {
                fila.push({w, altura_atual+1});
            }
        }
    }
    av = pai[v]; aw = pai[w];
    while (altura[av] < altura[aw]) aw = pai[aw];
    while (altura[av] > altura[aw]) av = pai[av];
    while (av != aw) {
        av = pai[av];
        aw = pai[aw];
    }
    return aw;
}

int main() {
    int t, n, m, q, v, w;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
        vector<vector<int>> g(n);
        vector<int> pai(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> m;
            vector<int> c(m);
            for (int j = 0; j < m; j++) {
                cin >> c[j];
                c[j]--;
                pai[c[j]] = i;
            }
            g[i] = c;
        }
        cin >> q;
        cout << "Case " << tt + 1 << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> v >> w;
            v--; w--;
            cout << lca(g, pai, v, w) + 1 << endl;
        }
    }
    return 0;
}
