#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, i, r, a, amigo, res = 0;
    cin >> n >> m;
    vector<int> amigos;
    vector<bool> infectado(n);
    bool infectar;
    cin >> i >> r;
    i--; r--;
    for (int k = 0; k < m; k++) {
        infectar = false;
        amigos.clear();
        if (k == r) infectado[i] = true;
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> amigo;
            amigo--;
            amigos.push_back(amigo);
            if (infectado[amigo]) {
                infectar = true;
            }
        }
        if (infectar) {
            for (int x : amigos) {
                infectado[x] = true;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        if (infectado[k]) res++;
    }
    cout << res << endl;
    return 0;
}
