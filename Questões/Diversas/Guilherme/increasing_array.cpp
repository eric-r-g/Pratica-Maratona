#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, moves = 0;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (ll i = 1; i < n; i++) {
        if (x[i] < x[i-1]) {
            moves += (x[i-1] - x[i]);
            x[i] = x[i-1];
        }
    }
    cout << moves << "\n";
    return 0;
}
