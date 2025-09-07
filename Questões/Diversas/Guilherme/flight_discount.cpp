#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<ll, ll, ll> tii;

int main() {
    int n, m, a, b, c;
    int v, u, d, w, cup;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    priority_queue<tii, vector<tii>, greater<tii>> fila;
    vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    fila.push({0, 0, 0});
    while(!fila.empty()) {
        auto[d, v, cup] = fila.top(); fila.pop();
        if (dist[v][cup] < d) continue;
        for (auto[u, w] : g[v]) {
            if (dist[u][cup] > d + w) {
                dist[u][cup] = d + w;
                fila.push({d + w, u, cup});
            }
            if (cup == 0 && dist[u][1] > d + w/2) {
                dist[u][1] = d + w/2;
                fila.push({d + w/2, u, 1});
            }
        }
    }
    cout << dist[n-1][1] << endl;
    return 0;
}
