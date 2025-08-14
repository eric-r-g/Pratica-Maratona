#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int dijkstra(vector<vector<pii>>& g) {
    int n = g.size();
    vector<bool> visitado(n);
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> fila;
    fila.push({0, 0});
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
    return dist[n-1];
}

int main() {
    int n, m, v, u, w, res;
    cin >> n >> m;
    vector<vector<pii>> g(n+2);
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    res = dijkstra(g);
    cout << res << endl;
    return 0;
}
