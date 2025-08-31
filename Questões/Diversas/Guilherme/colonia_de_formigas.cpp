#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long,long> pll;

int lca(vector<vector<int>>& ancestral, vector<int>& nivel, int s, int t) {
    if (s == t) return s;
    if (nivel[s] > nivel[t]) swap(s, t);
    if (nivel[s] == 0) return s;
    for (int i = 17; i >= 0; i--) {
        if (nivel[t] - nivel[s] >= (1<<i)) t = ancestral[t][i];
    }
    if (s == t) return s;
    for (int i = 17; i >= 0; i--) {
        if (ancestral[s][i] != -1 && ancestral[s][i] != ancestral[t][i]) {
            s = ancestral[s][i];
            t = ancestral[t][i];
        }
    }
    return ancestral[s][0];
}

vector<vector<int>> filhos;
vector<int> pai, comprimento, nivel;
vector<ll> dist;
vector<vector<int>> ancestral;
queue<int> fila;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, s, t, a, v;
    ll res;
    while(true) {
        cin >> n;
        if (n == 0) break;
        filhos = vector<vector<int>>(n);
        pai = vector<int>(n);
        comprimento = vector<int>(n);
        nivel = vector<int>(n);
        dist = vector<ll>(n);
        ancestral = vector<vector<int>>(n, vector<int>(18, -1));
        pai[0] = -1; comprimento[0] = 0;
        for (int i = 1; i < n; i++) {
            cin >> pai[i] >> comprimento[i];
            filhos[pai[i]].push_back(i);
        }
        fila.push(0);
        nivel[0] = 0;
        dist[0] = 0;
        while (!fila.empty()) {
            v = fila.front();
            fila.pop();
            for (int u : filhos[v]) {
                nivel[u] = nivel[v] + 1;
                dist[u] = dist[v] + comprimento[u];
                fila.push(u);
            }
        }
        for (int i = 1; i < n; i++) {
            ancestral[i][0] = pai[i];
        }
        for (int i = 1; i < 18; i++) {
            for (int j = 1; j < n; j++) {
                if (ancestral[j][i-1] > -1) ancestral[j][i] = ancestral[ancestral[j][i-1]][i-1];
            }
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> s >> t;
            a = lca(ancestral, nivel, s, t);
            res = dist[s] + dist[t] - 2 * dist[a];
            cout << res << " \n"[i==q-1];
        }
    }
    return 0;
}
