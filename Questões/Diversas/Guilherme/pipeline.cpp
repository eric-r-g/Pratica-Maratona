#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int main() {
    ll n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    if (n <= k) {
        cout << "1\n";
        return 0;
    }
    ll l = 0, m, r = k-2, soma_pa, res = -1;
    while (l <= r) {
        m = (l + r) / 2;
        soma_pa = (k*k - k - m*m + m) / 2 + 1;
        if (soma_pa >= n) {
            res = k - m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << res << "\n";
    return 0;
}
