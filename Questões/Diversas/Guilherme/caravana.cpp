#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p[1000], soma = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        soma += p[i];
    }
    for (int i = 0; i < n; i++) {
        cout << (soma / n) - p[i] << endl;
    }
    return 0;
}