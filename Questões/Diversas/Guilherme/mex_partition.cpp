#include <bits/stdc++.h>
#define NMAX 101
using namespace std;

void sol() {
    int n, a;
    vector<bool> b(NMAX);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        b[a] = true;
    }
    for (int i = 0; i < NMAX; i++) {
        if (b[i] == false) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) sol();
    return 0;
}
