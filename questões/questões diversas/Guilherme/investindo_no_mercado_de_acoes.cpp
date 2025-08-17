#include <bits/stdc++.h>
#define N_MAX 1000000
using namespace std;

int n, k, oldk = 0;
long long d[N_MAX] = {};

long long divide(int n) {
    if (n <= k) return 1;
    if (d[n-1] == 0) {
        if (n % 2 == 0) d[n-1] = 2 * divide(n/2);
        else d[n-1] = divide(n/2 + 1) + divide(n/2);
    }
    return d[n-1];
}

int main() {
    while (true) {
        if (oldk != k) {
            memset(d, 0, sizeof(d));
            oldk = k;
        }
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        cout << divide(n) << endl;
    }
    return 0;
}