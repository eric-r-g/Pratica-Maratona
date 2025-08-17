#include <bits/stdc++.h>
#define LENGTH 100
using namespace std;

// PROGRAMA INCOMPLETO

int main() {
    unsigned int n, xi, yi, xf, yf, maior = 0, res = 0, map[LENGTH] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xi >> xf >> yi >> yf;
        if (xf > maior) maior = xf;
        for (int j = yi - 1; j < yf; j++) {

        }
    }
    for (int i = 0; i < maior; i++) {
        res += popcount(map[i]);
    }
    cout << res << endl;
    return 0;
}