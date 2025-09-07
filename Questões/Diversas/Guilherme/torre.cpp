#include <bits/stdc++.h>
#define N_MAX 1000
using namespace std;

int main() {
    int n, tab[N_MAX][N_MAX], max = 0;
    int col[N_MAX] = {}, lin[N_MAX] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tab[i][j];
            col[j] += tab[i][j];
            lin[i] += tab[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = col[j] + lin[i] - 2 * tab[i][j];
            if (val > max) max = val;
        }
    }
    cout << max << "\n";
    return 0;
}