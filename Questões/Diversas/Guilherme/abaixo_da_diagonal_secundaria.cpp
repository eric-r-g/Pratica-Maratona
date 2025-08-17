#include <bits/stdc++.h>
using namespace std;

int main() {
    char O;
    double el, soma = 0.0;
    cin >> O;
    for (int i = 0; i < 144; i++) {
        cin >> el;
        if (i/12 > 11 - (i%12)) soma += el;
    }
    if (O == 'M') printf("%.1f\n", soma / 66.0);
    else printf("%.1f\n", soma);
    return 0;
}