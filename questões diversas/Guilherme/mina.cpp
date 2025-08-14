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
    int n, res;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<pii>> g(n*n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                g[(i-1)*n + j].push_back({i*n + j, grid[i][j]});
            }
            if (j > 0) {
                g[i*n + j-1].push_back({i*n + j, grid[i][j]});
            }
            if (i < n - 1) {
                g[(i+1)*n + j].push_back({i*n + j, grid[i][j]});
            }
            if (j < n - 1) {
                g[i*n + j+1].push_back({i*n + j, grid[i][j]});
            }
        }
    }
    res = dijkstra(g);
    cout << res << endl;
    return 0;
}
