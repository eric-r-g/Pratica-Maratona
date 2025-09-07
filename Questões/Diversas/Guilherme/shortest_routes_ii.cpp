#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<long long>> floyd_warshall(vector<vector<pii>>& g) {
    int n = g.size();
    vector<vector<long long>> dist(n, vector<long long>(n, LONG_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int v = g[i][j].first, w = g[i][j].second;
            if (w < dist[i][v]) dist[i][v] = w;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == LONG_MAX || dist[k][j] == LONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == LONG_MAX) dist[i][j] = -1;
        }
    }
    return dist;
}

int main() {
    int n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector<vector<pii>> g(n);
    vector<vector<long long>> dist;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dist = floyd_warshall(g);
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--; b--;
        cout << dist[a][b] << "\n";
    }
    return 0;
}
