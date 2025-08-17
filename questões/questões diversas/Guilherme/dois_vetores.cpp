#include <bits/stdc++.h>
using namespace std;

int main() {
    int impar[9], i = 0, l;
    for (int k = 0; k < 10; k++) {
        cin >> l;
        if (l % 2 == 0) cout << l << " "; // Lembrete: O resto da divisão de um número ímpar negativo por 2 é -1, não 1.
        else impar[i++] = l;
    }
    cout << endl;
    for (int k = 0; k < i; k++) {
        cout << impar[k] << " ";
    }
    cout << endl;
    return 0;
}