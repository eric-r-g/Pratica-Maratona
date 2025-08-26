#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<vector<int>> g(n);
        vector<int> grau(n);
        queue<int> fila;
        vector<int> lista;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            a--; b--;
            g[a].push_back(b);
            grau[b]++;
        }
        for (int i = 0; i < n; i++) {
            if (grau[i] == 0) fila.push(i);
        }
        while(!fila.empty()) {
            a = fila.front();
            fila.pop();
            lista.push_back(a);
            for (int b : g[a]) {
                grau[b]--;
                if (grau[b] == 0) fila.push(b);
            }
        }
        for (int i = 0; i < n-1; i++) {
            cout << lista[i]+1 << " ";
        }
        cout << lista[n-1]+1 << endl;
    }
    return 0;
}
