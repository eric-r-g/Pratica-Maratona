#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, pedacos = 0;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> i;
        pedacos += i - 1;
    }
    cout << pedacos << "\n";
    return 0;
}