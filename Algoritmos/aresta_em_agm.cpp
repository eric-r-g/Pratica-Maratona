#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

bool aux_aresta_em_agm(vector<vector<pii>>& g, vector<bool>& visitado, int v, int u, int w) {
    if (v == u) return false;
    visitado[v] = true;
    for (pii p : g[v]) {
        if (p.first < w && aux_aresta_em_agm(g, visitado, p.second, u, w) == false) return false;
    }
    return true;
}

bool aresta_em_agm(vector<vector<pii>>& g, int v, int u, int w) {
    int n = g.size();
    vector<bool> visitado(n);
    for (pii p : g[v]) {
        if (p.second != u && p.first < w && aux_aresta_em_agm(g, visitado, p.second, u, w) == false) return false;
    }
    return true;
}

int main() {_
    int n, m, v, u, w;
    cin >> n;
    vector<vector<pii>> g(n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        v--; u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }
    cin >> v >> u;
    v--; u--;
    for (pii p : g[v]) {
        if (p.second == u) {
            w = p.first;
            break;
        }
    }
    aresta_em_agm(g, v, u, w);
    return 0;
}
