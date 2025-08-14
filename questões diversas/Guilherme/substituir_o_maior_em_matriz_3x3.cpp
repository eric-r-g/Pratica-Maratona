#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int map[3][3], maior = INT_MIN;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
            if (map[i][j] > maior) maior = map[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == maior) cout << -1;
            else cout << map[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}