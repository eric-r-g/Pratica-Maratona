#include <bits/stdc++.h>
using namespace std;

int main() {
    int c;
    double el, soma = 0.0;
    char t;
    cin >> c;
    cin >> t;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> el;
            if (j == c) soma += el; 
        }
    }
    if (t == 'M') printf("%.1f\n", soma / 12.0);
    else printf("%.1f\n", soma);
    return 0;
}