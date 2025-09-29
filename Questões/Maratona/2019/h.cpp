#include <bits/stdc++.h>
using namespace std;

int main() {
    double v, n; cin >> v >> n;
    double q = v * n;
    for (double i = 1.0; i <= 9.0; i++) {
        cout << (int) ceil(q * i / 10.0) << " \n"[i == 9];
    }
    return 0;
}
