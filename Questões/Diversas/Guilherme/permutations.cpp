#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) cout << 1;
    else if (n <= 3) cout << "NO SOLUTION";
    else {
        for (int i = n - n/2; i > 2; i--) {
            cout << i * 2 - 1 << " ";
        }
        cout << "2 4 1 3";
        for (int i = 3; i <= n/2; i++) {
            cout << " " << i * 2;
        }
    }
    cout << "\n";
    return 0;
}
