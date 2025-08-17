#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string inp;
    vector<string> nomes;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> inp;
        nomes.push_back(inp);
    }
    sort(nomes.begin(), nomes.end());
    cout << nomes[k - 1] << endl;
    return 0;
}
