#include <bits/stdc++.h>
using namespace std;

int pow(int a, int n) {
    int r = a;
    for (int i = 1; i <= n-1; i++) {
        r *= a;
    }
    return r;
}

int binpow(int a, int b) {
    if (b == 0) return 1;
    int res = binpow(a, b/2);
    if (b % 2 == 0) return res * res;
    return res * res * a;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {

    return 0;
}
