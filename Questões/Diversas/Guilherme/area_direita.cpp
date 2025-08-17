#include <bits/stdc++.h>
using namespace std;

int main() {
    char O;
    double el, soma = 0.0;
    cin >> O;
    for (int c = 0; c < 144; c++) {
        int i = c / 12, j = c % 12;
        cin >> el;
        if (i < j && 11 - j < i) soma += el;
    }
    if (O == 'M') printf("%.1f\n", soma / 30.0);
    else printf("%.1f\n", soma);
    return 0;
}