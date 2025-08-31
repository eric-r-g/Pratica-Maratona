#include <bits/stdc++.h>
using namespace std;

void aux_calcular_distancias(vector<vector<int>>& g, vector<int>& distancia, vector<bool>& visitado, int v, int dist) {
    visitado[v] = true;
    distancia[v] = dist;
    for (int u : g[v]) {
        if (visitado[u] == false) {
            aux_calcular_distancias(g, distancia, visitado, u, dist+1);
        }
    }
}

void calcula_distancias(vector<vector<int>>& g, vector<int>& distancia, int v) {
    int n = g.size();
    vector<bool> visitado(n);
    aux_calcular_distancias(g, distancia, visitado, v, 0);
}

int main() {
    int n, a, b, maior = 0, v, u;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> distancia_v(n), distancia_u(n), distancia(n);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calcula_distancias(g, distancia_v, 0);
    for (int i = 0; i < n; i++) {
        if (distancia_v[i] > maior) {
            maior = distancia_v[i];
            v = i;
        }
    }
    calcula_distancias(g, distancia_v, v);
    for (int i = 0; i < n; i++) {
        if (distancia_v[i] > maior) {
            maior = distancia_v[i];
            u = i;
        }
    }
    calcula_distancias(g, distancia_u, u);
    for (int i = 0; i < n-1; i++) {
        cout << max(distancia_v[i], distancia_u[i]) << " ";
    }
    cout << max(distancia_v[n-1], distancia_u[n-1]) << "\n";
    return 0;
}
