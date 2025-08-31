#include <bits/stdc++.h>
using namespace std;

int main() {
    int input, f[99] = {}, acertos = 0;
    for (int i = 0; i < 6; i++) {
        cin >> input;
        f[input-1] = 1;
    }
    for (int i = 0; i < 6; i++) {
        cin >> input;
        if (f[input-1] == 1) acertos++;
    }
    switch (acertos) {
        case 3:
        cout << "terno";
        break;
        case 4:
        cout << "quadra";
        break;
        case 5:
        cout << "quina";
        break;
        case 6:
        cout << "sena";
        break;
        default:
        cout << "azar";
        break;
    }
    cout << "\n";
    return 0;
}