#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    vector<pair<int,int>> pares;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pair<int,int> par = {y, x};
        pares.push_back(par);
    }
    sort(pares.begin(), pares.end());
    y = pares[0].first;
    int res = 1;
    for (auto par : pares) {
        if (par.second >= y) {
            res++;
            y = par.first;
        }
    }
    cout << res << endl;
    return 0;
}