#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n, a, max = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > max) max = a;
    }
    cout << max << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) sol();
    return 0;
}
