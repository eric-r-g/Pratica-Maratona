#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int dijkstra(vector<vector<pii>>& g, int s) {
    int n = g.size();
    vector<bool> visitado(n);
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, s});
    while(!fila.empty()) {
        int v = fila.top().second;
        fila.pop();
        if (visitado[v]) continue;
        visitado[v] = true;
        for (pii pu : g[v]) {
            int u = pu.first, w = pu.second;
            if (dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                fila.push({dist[u], u});
            }
        }
    }
    int maior = 0, menor = INT_MAX;
    for (int v = 0; v < n; v++) {
        if (dist[v] > maior) maior = dist[v];
        if (v != s && dist[v] < menor) menor = dist[v];
    }
    return maior - menor;
}

int main() {
    int n, m, u, v, p, s;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        u--; v--;
        g[u].push_back({v, p});
        g[v].push_back({u, p});
    }
    cin >> s;
    s--;
    cout << dijkstra(g, s) << endl;
    return 0;
}
