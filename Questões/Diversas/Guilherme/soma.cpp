#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k, p, u, e, d, m, s;
    ll res = 0, rem = 0;
    cin >> n >> k;
    vector<int> v(n);
    vector<ll> pref(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    pref[0] = v[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + v[i];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) rem = pref[i-1];
        p = -1;
        e = i; d = n-1;
        while (e <= d) {
            m = (e + d) / 2;
            s = pref[m] - rem;
            if (s == k) {
                p = m;
                d = m-1;
            } else if (s < k) {
                e = m+1;
            } else {
                d = m-1;
            }
        }
        u = n;
        e = i; d = n-1;
        while (e <= d) {
            m = (e + d) / 2;
            s = pref[m] - rem;
            if (s > k) {
                u = m;
                d = m-1;
            } else {
                e = m+1;
            }
        }
        if (p != -1) res += u - p;
    }
    cout << res << endl;
    return 0;
}
