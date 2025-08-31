#include <bits/stdc++.h>
using namespace std;

int main() {
    int map[3][3], soma, s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }
    soma = map[0][0] + map[0][1] + map[0][2];
    for (int i = 1; i < 3; i++) { // Linhas
        s = 0;
        for (int j = 0; j < 3; j++) {
            s += map[i][j];
        }
        if (s != soma) {
            cout << "NAO" << "\n";
            exit(0);
        }
    }
    for (int i = 0; i < 3; i++) { // Colunas
        s = 0;
        for (int j = 0; j < 3; j++) {
            s += map[j][i];
        }
        if (s != soma) {
            cout << "NAO" << "\n";
            exit(0);
        }
    }
    s = 0;
    for (int i = 0; i < 3; i++) { // Diagonal principal
        s += map[i][i];
    }
    if (s != soma) {
        cout << "NAO" << "\n";
        exit(0);
    }
    s = 0;
    for (int i = 0; i < 3; i++) { // Diagonal secundária
        s += map[i][2-i];
    }
    if (s != soma) {
        cout << "NAO" << "\n";
        exit(0);
    }
    cout << "SIM" << "\n";
    return 0;
}