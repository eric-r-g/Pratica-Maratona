#include <bits/stdc++.h>
using namespace std;

void dfs(vector<string> &grid, int a, int b) {
    int n = grid.size(), m = grid[0].size();
    grid[a][b] = 'o';
    if (a == n - 1) return;
    if (grid[a+1][b] == '#' && b > 0 && grid[a][b-1] == '.') dfs(grid, a, b-1);
    if (grid[a+1][b] == '#' && b < m - 1 && grid[a][b+1] == '.') dfs(grid, a, b+1);
    if (grid[a+1][b] == '.') dfs(grid, a+1, b);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 'o') {
            dfs(grid, 0, i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
    return 0;
}
