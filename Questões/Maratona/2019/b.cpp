#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, carlos; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    carlos = v[0];
    sort(v.begin(), v.end(), greater<int>());
    if (carlos == v[0]) cout << "S";
    else cout << "N";
    cout << "\n";
    return 0;
}
