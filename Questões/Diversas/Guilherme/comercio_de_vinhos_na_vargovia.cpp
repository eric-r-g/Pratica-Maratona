#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, dem, custo;
    while(true) {
        dem = custo = 0;
        cin >> n;
        if (n == 0) break;
        for (long long i = 0; i < n; i++) {
            cin >> a;
            dem += a;
            custo += abs(dem);
        }
        cout << custo << endl;
    }
    return 0;
}