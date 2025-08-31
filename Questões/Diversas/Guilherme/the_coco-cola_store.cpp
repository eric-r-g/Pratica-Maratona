#include <bits/stdc++.h>
#define N_MAX 100
using namespace std;

int main() {
    int n, q, r, cheias;
    while (true) {
        cheias = 0;
        cin >> n;
        if (n == 0) break;
        do {
            r = n % 3;
            q = n / 3;
            cheias += q;
            n = r + q;
        } while (q > 0);
        if (r == 2) cheias++;
        cout << cheias << "\n";
    }
    return 0;
}