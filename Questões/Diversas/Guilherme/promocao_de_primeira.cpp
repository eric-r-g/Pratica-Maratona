// Aqui eu resolvi testar o uso dos índices dos vetores no estilo Lua

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> tii;

tii dfs(vector<vector<pii>>& g, vector<bool>& visitado, int v) {
    visitado[v] = true;
    int mp, mb, mm;
    mp = mb = mm = 1;
    tii ret;
    for (pii p : g[v]) {
        if (!visitado[p.first]) {
            ret = dfs(g, visitado, p.first);
            if (p.second == 0 && ret[1] + 1 > mp) mp = ret[1] + 1;
            if (p.second == 1 && ret[0] + 1 > mb) mb = ret[0] + 1;
            if (ret[2] > mm) mm = ret[2];
        }
    }
    return {mp, mb, max(mm, mp + mb - 1)};
}

int main() {
    int n, a, b, e, maior = 0;
    tii ret;
    cin >> n;
    vector<vector<pii>> g(n+1);
    vector<bool> visitado(n+1);
    for (int i = 1; i <= n-1; i++) {
        cin >> a >> b >> e;
        g[a].push_back({b,e});
        g[b].push_back({a,e});
    }
    ret = dfs(g, visitado, 2);
    cout << ret[2] << "\n";
    return 0;
}
