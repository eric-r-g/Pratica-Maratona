// Baseado em https://japlslounge.com/posts/cses/two_knights/1.htm
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    long long res;
    for (long long k = 1; k <= n; k++) {
        res = (k*k * (k*k - 1)) / 2 - 4 * (k - 1) * (k - 2);
        cout << res << "\n";
    }
    return 0;
}
