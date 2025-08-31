#include <bits/stdc++.h>
#define LENGTH 100
using namespace std;

int main() {
    int n, xi, xf, yi, yf, res = 0;
    bool map[LENGTH][LENGTH] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xi >> xf >> yi >> yf;
        xi--; xf--; yi--; yf--;
        for (int y = yi; y < yf; y++) {
            for (int x = xi; x < xf; x++) {
                if (map[y][x] == false) res++;
                map[y][x] = true;
            }
        }
    }
    cout << res << "\n";
    return 0;
}