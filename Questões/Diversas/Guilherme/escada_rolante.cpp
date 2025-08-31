#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t1, t2, res = 0;
    cin >> n;
    cin >> t2;
    res += 10;
    for (int i = 1; i < n; i++) {
        t1 = t2;
        cin >> t2;
        if (t2 >= t1 + 10) res += 10;
        else res += (t2 - t1);
    }
    cout << res << "\n";
    return 0;
}
