#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

int main() {_
    int n, m, v, u, w;
    cin >> n;
    vector<vector<pii>> g(n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> v >> u >> w;
        v--; u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }
    return 0;
}
