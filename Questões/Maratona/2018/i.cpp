#include <bits/stdc++.h>

using namespace std;
int main() {
    int n, m, l, x, k, y;
    bool desl;
    cin >> n >> m;
    vector<bool> ligada(m, false);
    vector<vector<int>> alterna(n);
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x;
        ligada[x-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> y;
            y--;
            alterna[i].push_back(y);
        }
    }
    for (int i = 0; i <= 2*n - 2; i++) {
        for (int j = 0; j < alterna[i%n].size(); j++) {
            ligada[alterna[i%n][j]] = 1 - ligada[alterna[i%n][j]];
        }
        desl = true;
        for (int j = 0; j < m; j++) {
            if (ligada[j]) {
                desl = false;
                break;
            }
        }
        if (desl) {
            cout << (i + 1) << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
