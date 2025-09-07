#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, as = 0, res = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') as++;
        else {
            if (as > 1) res += as;
            as = 0;
        }
    }
    if (as > 1) res += as;
    cout << res << endl;
    return 0;
}
