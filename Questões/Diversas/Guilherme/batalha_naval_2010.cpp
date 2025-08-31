// . água
// # parte de barco não encontrado
// % parte de barco encontrado
// @ parte de barco (encontrado) afundada

#include <bits/stdc++.h>
using namespace std;

void acertou_aux(vector<string> &grid, int l, int c) {
    static int n = grid.size(), m = grid[0].size();
    grid[l][c] = '%';
    if (c < m - 1 && grid[l][c+1] == '#') acertou_aux(grid, l, c+1);
    if (l > 0 && grid[l-1][c] == '#') acertou_aux(grid, l-1, c);
    if (c > 0 && grid[l][c-1] == '#') acertou_aux(grid, l, c-1);
    if (l < n - 1 && grid[l+1][c] == '#') acertou_aux(grid, l+1, c);
}

bool acertou(vector<string> &grid, int l, int c) {
    if (grid[l][c] == '.') return false;
    if (grid[l][c] != '#') {
        grid[l][c] = '@';
        return false;
    }
    acertou_aux(grid, l, c);
    grid[l][c] = '@';
    return true;
}

bool pontuou(vector<string> &grid, int l, int c) {
    static int n = grid.size(), m = grid[0].size();
    bool ret = true;
    grid[l][c] = '.';
    if (c < m - 1 && grid[l][c+1] == '@' && pontuou(grid, l, c+1) == false) ret = false;
    else if (l > 0 && grid[l-1][c] == '@' && pontuou(grid, l-1, c) == false) ret = false;
    else if (c > 0 && grid[l][c-1] == '@' && pontuou(grid, l, c-1) == false) ret = false;
    else if (l < n - 1 && grid[l+1][c] == '@' && pontuou(grid, l+1, c) == false) ret = false;
    else if (c < m - 1 && grid[l][c+1] == '%') ret = false;
    else if (l > 0 && grid[l-1][c] == '%') ret = false;
    else if (c > 0 && grid[l][c-1] == '%') ret = false;
    else if (l < n - 1 && grid[l+1][c] == '%') ret = false;
    if (ret == false) {
        grid[l][c] = '@';
    }
    return ret;
}

int main() {
    int n, m, k, l, c, encontrados = 0, res = 0;
    vector<pair<int,int>> pos_encontrados;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> l >> c;
        l--; c--;
        if (acertou(grid, l, c)) {
            encontrados++;
            pos_encontrados.push_back({l,c});
        }
    }
    for (pair<int,int> p : pos_encontrados) {
        if (pontuou(grid, p.first, p.second)) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
