#include <bits/stdc++.h>
#define N_MAX 10000
using namespace std;

int main() {
    int n, fita[N_MAX], cont = 0, zi = -1, zf;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> fita[i];
        if (fita[i] == 0) {
            if (zi == -1) zi = i;
            zf = i;
        }
    }
    for (int i = zi; i < n; i++) {
        if (cont < 9) cont++;
        if (fita[i] == 0) cont = 0;
        else fita[i] = cont;
    }
    cont = 0;
    for (int i = zf; i >= 0; i--) {
        if (cont < 9) cont++;
        if (fita[i] == 0) cont = 0;
        else if (fita[i] == -1 || fita[i] > cont) fita[i] = cont; 
    }
    for (int i = 0; i < n; i++) {
        cout << fita[i] << " ";
    }
    cout << "\n";
    return 0;
}