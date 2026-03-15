#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto[b, c] : g[i]) {
            dist[i][b] = c;
        }
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}
