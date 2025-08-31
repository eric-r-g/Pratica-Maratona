#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, c;
    int pag, lin, letras;
    string pal;
    while (cin >> n >> l >> c) {
        pag = 1; lin = 1; letras = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> pal;
            letras += pal.size();
            if (letras > c) {
                lin++;
                letras = pal.size();
            }
            if (lin > l) {
                pag++;
                lin = 1;
            }
            // espaço em branco
            letras++;
            if (letras > c) {
                lin++;
                letras = 0;
            }
            if (lin > l) {
                pag++;
                lin = 1;
            }
        }
        // A última palavra não é seguida de um espaço
        cin >> pal;
        letras += pal.size();
        if (letras > c) {
            lin++;
            letras = pal.size();
        }
        if (lin > l) {
            pag++;
            lin = 1;
        }
        cout << pag << "\n";
    }
    return 0;
}
