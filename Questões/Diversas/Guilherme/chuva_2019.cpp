#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void empilha(vector<string> &grid, queue<pair<int,int>> &q, int a, int b) {
    if (grid[a][b] != 'o') {
        q.push({a,b});
    }
}

void bfs(vector<string> &grid, int a, int b) {
    queue<pair<int,int>> q;
    static int n = grid.size(), m = grid[0].size();
    int x, y;
    q.push({a,b});
    while(!q.empty()) {
        // a,b é linha,coluna, ou seja, y,x
        y = q.front().first;
        x = q.front().second;
        q.pop();
        grid[y][x] = 'o';
        if (y < n - 1) {
            if (y % 2 == 0) {
                if (x > 0 && grid[y+1][x] == '#') empilha(grid, q, y, x-1);
                if (x < m - 1 && grid[y+1][x] == '#') empilha(grid, q, y, x+1);
                if (grid[y+1][x] == '.') empilha(grid, q, y+1, x);
            } else {
                empilha(grid, q, y+1, x);
            }
        }
    }
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
            bfs(grid, 0, i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
    return 0;
}
