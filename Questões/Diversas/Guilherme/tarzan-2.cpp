#include <bits/stdc++.h>
using namespace std;

typedef enum cor {
    branco,
    cinza,
    preto
} cor;

void dfs(vector<vector<cor>> &cores, int d, int a, int b, int xmax, int ymax) {
    int z;
    int x, y;

    cores[a][b] = cinza;

    for (int i = -d; i <= d; i++) {
        x = b + i;
        y = a + i;
        if (!(x < 0 || x > xmax)) {
            if (cores[a][x] == branco) dfs(cores, d, x, a, xmax, ymax);
        }
        if (!(y < 0 || y > ymax)) {
            if (cores[y][b] == branco) dfs(cores, d, y, b, xmax, ymax);
        }
    }

    cores[a][b] = preto;
}

int main() {
    int n, d, xmax = 0, ymax = 0, a, b;
    bool res = true;
    cin >> n >> d;
    vector<vector<cor>> cores(5000, vector<cor>(5000, preto));
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cores[a][b] = branco;
        if (a > xmax) xmax = a;
        if (b > ymax) ymax = b;
    }
    dfs(cores, d, a, b, xmax, ymax);
    for (int y = 0; y <= ymax; y++) {
        for (int x = 0; x <= xmax; x++) {
            if (cores[y][x] == branco) {
                res = false;
                goto superbreak;
            }
        }
    }
    superbreak:
    if (res) cout << "S";
    else cout << "N";
    cout << "\n";
    return 0;
}
