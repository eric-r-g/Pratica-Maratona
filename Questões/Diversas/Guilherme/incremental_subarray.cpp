#include <bits/stdc++.h>

using namespace std;
vector<int> a;

int main() {
    int t, n, m;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n >> m;
        a.resize(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        // if (m == 1) cout << (n - a[m-1] + 1) << "\n";
        // else if (a[m-1] <= a[0] || a[m-1] - a[0] + 1 < m) cout << "1\n";
        // else cout << (n - a[m-1] - a[0] + 2) << "\n";
        if (a[m-1] <= a[0]) cout << "1\n";
        else cout << (n - a[m-1] + 1);
    }
    return 0;
}
