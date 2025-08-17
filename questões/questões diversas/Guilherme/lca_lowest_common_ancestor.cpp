#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

int lca(vector<vector<int>>& g, vector<int>& pai, int v, int w, int tt) {
    int n = g.size();
    // Talvez o melhor a se fazer fosse atribuir um valor padrão suficientemente grande para l
    // no lugar de realizar uma operação tão complexa quanto a de logaritmo com mudança de base...
    int l = ceil(log(n)/log(2));
    int u;
    queue<pii> fila;
    int raiz = -1;
    static vector<int> nivel;
    static vector<vector<int>> ancestral;
    static int ttt = -1;
    if (l == 0) return v;
    if (ttt != tt) {
        ttt = tt;
        nivel = vector<int>(n);
        for (int i = 0; i < n; i++) {
            if (pai[i] == -1) {
                raiz = i;
                break;
            }
        }
        fila.push({raiz, 1});
        while(!fila.empty()) {
            u = fila.front().first;
            nivel[u] = fila.front().second;
            fila.pop();
            for (int z : g[u]) {
                if (nivel[z] == 0) fila.push({z, nivel[u]+1});
            }
        }
        ancestral = vector<vector<int>>(n, vector<int>(l, -1));
        for (int i = 0; i < n; i++) {
            ancestral[i][0] = pai[i];
        }
        for (int j = 1; j < l; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestral[i][j-1] != -1) {
                    ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
                }
            }
        }
    }

    if (nivel[w] < nivel[v]) swap(v, w);

    for (int i = l-1; i >= 0; i--) {
        if (nivel[w] - (1<<i) >= nivel[v]) {
            w = ancestral[w][i];
        }
    }

    if (v == w) return v;

    for (int i = l-1; i >= 0; i--) {
        if (ancestral[v][i] != -1 && ancestral[v][i] != ancestral[w][i]) {
            v = ancestral[v][i];
            w = ancestral[w][i];
        }
    }

    return pai[v];
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
            vector<int> filhos(m);
            for (int j = 0; j < m; j++) {
                cin >> filhos[j];
                filhos[j]--;
                pai[filhos[j]] = i;
            }
            g[i] = filhos;
        }
        cin >> q;
        cout << "Case " << tt+1 << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> v >> w;
            v--; w--;
            cout << lca(g, pai, v, w, tt)+1 << endl;
        }
    }
    return 0;
}
