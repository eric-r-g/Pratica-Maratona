#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    ll y, x, M, diff;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> y >> x;
        y--; x--;
        M = max(y, x);
        if (M % 2 == 0) {
            diff = x - y;
        } else diff = y - x;
        cout << M*M + M + 1 + diff << "\n";
    }
    return 0;
}
