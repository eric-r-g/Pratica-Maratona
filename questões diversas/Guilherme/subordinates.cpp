#include <bits/stdc++.h>
using namespace std;

int conta_subordinados(vector<vector<int>>& g, vector<int>& sub, int v, int p) {
    int f = g[v].size();
    if (v != 0) {
        f--;
    }
    int subordinados = f;
    for (int u : g[v]) {
        if (u == p) continue;
        subordinados += conta_subordinados(g, sub, u, v);
    }
    sub[v] = subordinados;
    return subordinados;
}

int main() {
    int n, b;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> sub(n); // subordinados
    for (int i = 0; i < n-1; i++) {
        cin >> b;
        b--;
        g[b].push_back(i+1);
        g[i+1].push_back(b);
    }
    conta_subordinados(g, sub, 0, -1);
    for (int i = 0; i < n-1; i++) {
        cout << sub[i] << " ";
    }
    cout << sub[n-1] << endl;
    return 0;
}
