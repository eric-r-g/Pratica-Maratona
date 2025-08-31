#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x, y;
    bool res = true;
    cin >> n >> d;
    vector<pair<int,int>> arvores(n);
    vector<vector<int>> g(n);
    vector<bool> visitado(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arvores[i] = {x,y};
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int dx = arvores[i].first - arvores[j].first;
            int dy = arvores[i].second - arvores[j].second;
            long dist_quad = (long) dx * dx + dy * dy;
            if (d*d >= dist_quad) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    stack<int> s;
    s.push(0);
    while(!s.empty()) {
        int i = s.top();
        s.pop();
        visitado[i] = true;
        for (int j : g[i]) {
            if (visitado[j] == false) {
                s.push(j);
            }
        }
    }

    for (bool vis : visitado) {
        if (!vis) {
            res = false;
            break;
        }
    }
    if (res) cout << 'S';
    else cout << 'N';
    cout << "\n";

    return 0;
}
