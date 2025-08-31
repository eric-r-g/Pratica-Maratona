#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l, inp;
    cin >> n >> l;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> disp;
    vector<int> vezes(n);
    for (int i = 0; i < n; i++) {
        pair<int,int> p = {0, i};
        disp.push(p);
    }
    for (int i = 0; i < l; i++) {
        cin >> inp;
        pair<int,int> t = disp.top();
        pair<int,int> p = {inp + t.first, t.second};
        vezes[t.second]++;
        disp.pop();
        disp.push(p);
    }
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << " " << vezes[i] << "\n";
    }
    return 0;
}