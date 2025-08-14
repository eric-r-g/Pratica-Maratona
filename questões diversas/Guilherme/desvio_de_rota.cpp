#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int dijkstra(vector<vector<pii>>& g, int s, int c) {
    int n = g.size();
    vector<bool> visitado(n);
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, s});

    vector<int> rota(c);

    // rota[c-1] = 0
    for (int i = c - 2; i >= 0; i--) {
        int w;
        for (pii pj : g[i]) {
            if (pj.first == i + 1) {
                w = pj.second;
                break;
            }
        }
        rota[i] = rota[i+1] + w;
    }

    while(!fila.empty()) {
        int v = fila.top().second;
        fila.pop();
        if (visitado[v]) continue;
        visitado[v] = true;
        for (pii pu : g[v]) {
            int u = pu.first, w = pu.second;
            if (u < c) {
                if (dist[v] + w + rota[u] < dist[c-1]) dist[c-1] = dist[v] + w + rota[u];
            }
            else if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                fila.push({dist[u], u});
            }
        }
    }
    return dist[c-1];
}

int main() {
    int n, m, c, k, u, v, p;
    while (true) {
        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k == 0) break;
        vector<vector<pii>> g(n);
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            g[u].push_back({v, p});
            g[v].push_back({u, p});
        }
        cout << dijkstra(g, k, c) << endl;
    }
    return 0;
}
