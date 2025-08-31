#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, du, tri, quad, p1 = 0, p2;
    vector<int> c(5);
    bool cresce;
    cin >> n;
    for (int t = 0; t < n; t++) {
        vector<int> rep(13);
        for (int i = 0; i < 5; i++) {
            cin >> c[i];
            rep[c[i] - 1]++;
        }
        sort(c.begin(), c.end());
        cresce = true;
        for (int i = 1; i < 5; i++) {
            if (c[i] != c[i-1] + 1) cresce = false;
        }
        cout << "Teste " << t+1 << endl;
        if (cresce) cout << c[0] + 200;
        else {
            du = tri = quad = 0;
            for (int i = 0; i < 13; i++) {
                if (rep[i] == 2) {
                    du++;
                    p2 = p1;
                    p1 = i+1;
                }
                else if (rep[i] == 3) tri++;
                else if (rep[i] == 4) quad++;
            }
            if (quad == 1) cout << c[2] + 180;
            else if (tri == 1 && du == 1) cout << c[2] + 160;
            else if (tri == 1) cout << c[2] + 140;
            else if (du == 2) cout << 3 * p1 + 2 * p2 + 20;
            else if (du == 1) cout << p1;
            else cout << 0;
        }
        cout << endl << endl;
    }
    return 0;
}
