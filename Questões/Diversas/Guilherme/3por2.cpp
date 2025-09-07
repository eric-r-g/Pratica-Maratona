#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<int>());
    for (int i = 0; i < n; i += 3) {
        res += p[i];
    }
    for (int i = 1; i < n; i += 3) {
        res += p[i];
    }
    cout << res << "\n";
    return 0;
}
