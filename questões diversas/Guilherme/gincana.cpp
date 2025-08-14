#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& visitados, int i) {
    visitados[i] = true;
    for (int j : g[i]) {
        if (visitados[j] == false) dfs(g, visitados, j);
    }
}

int main() {
    int n, m, i, j, grupos = 0;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<bool> visitados(n);
    for (int a = 0; a < m; a++) {
        cin >> i >> j;
        i--; j--;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    for (int a = 0; a < n; a++) {
        if (visitados[a] == false) {
            grupos++;
            dfs(g, visitados, a);
        }
    }
    cout << grupos << endl;
    return 0;
}
