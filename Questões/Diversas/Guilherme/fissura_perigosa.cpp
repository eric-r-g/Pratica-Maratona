#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, f;
    cin >> n >> f;
    vector<string> gridchar(n);
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<bool>> gridbool(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        cin >> gridchar[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = gridchar[i][j] - '0';
        }
    }
    stack<pii> pilha;
    if (grid[0][0] <= f) pilha.push({0, 0});
    while (!pilha.empty()) {
        pii p = pilha.top();
        pilha.pop();
        if (gridbool[p.first][p.second]) continue;
        gridchar[p.first][p.second] = '*';
        gridbool[p.first][p.second] = true;
        if (p.first > 0 && grid[p.first-1][p.second] <= f) pilha.push({p.first-1, p.second});
        if (p.second > 0 && grid[p.first][p.second-1] <= f) pilha.push({p.first, p.second-1});
        if (p.first < n-1 && grid[p.first+1][p.second] <= f) pilha.push({p.first+1, p.second});
        if (p.second < n-1 && grid[p.first][p.second+1] <= f) pilha.push({p.first, p.second+1});
    }
    for (int i = 0; i < n; i++) {
        cout << gridchar[i] << "\n";
    }
    return 0;
}
