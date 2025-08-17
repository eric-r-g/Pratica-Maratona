#include <bits/stdc++.h>
using namespace std;

// Fiz esse programa do jeito que me pareceu mais engraçado.

int main() {
    int a, b;
    cin >> a;
    a %= 3;
    cin >> b;
    b = b % 3 == a ? (a + 1) % 3 : b % 3;
    cout << 3 - a - b << endl;
    return 0;
}