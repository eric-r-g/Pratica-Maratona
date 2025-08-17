#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, pedras[100] = {};
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int p, d;
        cin >> p >> d;
        for (int j = p-1; j >= 0; j -= d) {
            pedras[j] = 1;
        }
        for (int j = p-1; j < n; j += d) {
            pedras[j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << pedras[i] << endl;
    }
    return 0;
}