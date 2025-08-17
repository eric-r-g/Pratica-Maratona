#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &grid, int a, int b) {
    static int vis = 0;
    int n = grid.size(), m = grid[0].size();
    vis++;
    grid[a][b] = 1;
    if (a > 0 && grid[a-1][b] == 0) dfs(grid, a-1, b);
    if (a > 0 && b > 0 && grid[a-1][b-1] == 0) dfs(grid, a-1, b-1);
    if (a > 0 && b < m - 1 && grid[a-1][b+1] == 0) dfs(grid, a-1, b+1);
    if (b > 0 && grid[a][b-1] == 0) dfs(grid, a, b-1);
    if (b < m - 1 && grid[a][b+1] == 0) dfs(grid, a, b+1);
    if (a < n - 1 && grid[a+1][b] == 0) dfs(grid, a+1, b);
    if (a < n - 1 && b > 0 && grid[a+1][b-1] == 0) dfs(grid, a+1, b-1);
    if (a < n - 1 && b < m - 1 && grid[a+1][b+1] == 0) dfs(grid, a+1, b+1);
    grid[a][b] = 2;
    return vis;
}

int main() {
    int n, m, x, y, k, a, b;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        grid[a-1][b-1] = 2;
    }
    cout << dfs(grid, x-1, y-1) << endl;
    return 0;
}
