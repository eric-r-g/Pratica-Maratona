#include <bits/stdc++.h>
#define TAM 31
using namespace std;

int main() {
    int n, m, esq[TAM] = {}, dir[TAM] = {}, pares = 0;
    char l;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> l;
        m -= 30;
        if (l == 'E') esq[m]++;
        else dir[m]++;
        if (esq[m] > 0 && dir[m] > 0) {
            esq[m]--;
            dir[m]--;
            pares++;
        }
    }
    cout << pares << "\n";
    return 0;
}