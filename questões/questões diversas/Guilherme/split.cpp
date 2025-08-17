#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100], maior = 0, i, soma;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > maior) maior = a[i];
    }
    soma = 0;
    for (i = 0; a[i] != maior; i++) soma += a[i];
    cout << soma << endl;
    i++;
    soma = 0;
    for (i; i < n; i++) soma += a[i];
    cout << soma << endl;
    return 0;
}