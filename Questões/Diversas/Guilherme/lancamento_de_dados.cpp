#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, resultado, repeticoes[12] = {}, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> resultado;
        repeticoes[resultado-1]++;
        if (repeticoes[resultado-1] > max)
            max = repeticoes[resultado-1];
    }
    for (int i = 0; i < 12; i++) {
        if (repeticoes[i] == max) cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}