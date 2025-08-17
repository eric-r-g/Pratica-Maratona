#include <bits/stdc++.h>
#define N_MAX 100
using namespace std;

int main() {
    int n, m, x;
    int figs[N_MAX] = {};
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (figs[x-1] == 0) n--; 
        figs[x-1] = 1;
    }
    cout << n << endl;
    return 0;
}