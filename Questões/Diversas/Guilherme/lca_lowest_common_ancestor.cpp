#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int lca(vector<vector<int>>& ancestral, vector<int>& nivel, int v, int u) {
    if (nivel[u] < nivel[v]) swap(u, v);

    for (int i = 10; i >= 0; i--) {
        if (nivel[u] - (1<<i) >= nivel[v]) {
            u = ancestral[u][i];
        }
    }

    if (v == u) return v;

    for (int i = 10; i >= 0; i--) {
        if (ancestral[v][i] != -1 && ancestral[v][i] != ancestral[u][i]) {
            v = ancestral[v][i];
            u = ancestral[u][i];
        }
    }

    return ancestral[v][0];
}

int main() {
    int t, n, m, f, q, v, u, raiz;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
        vector<vector<int>> filhos(n);
        vector<int> pai(n, -1), nivel(n);
        vector<vector<int>> ancestral(n, vector<int>(11, -1));
        queue<pii> fila;
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> f;
                f--;
                filhos[i].push_back(f);
                pai[f] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (pai[i] == -1) {
                raiz = i;
                break;
            }
        }
        fila.push({raiz, 1});
        while (!fila.empty()) {
            int a = fila.front().first;
            nivel[a] = fila.front().second;
            fila.pop();
            for (int b : filhos[a]) {
                fila.push({b, nivel[a]+1});
            }
        }
        for (int i = 0; i < n; i++) {
            ancestral[i][0] = pai[i];
        }
        for (int j = 1; j < 11; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestral[i][j-1] != -1) ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
            }
        }
        cin >> q;
        cout << "Case " << tt+1 << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> v >> u;
            v--; u--;
            cout << lca(ancestral, nivel, v, u)+1 << endl;
        }
    }
    return 0;
}
