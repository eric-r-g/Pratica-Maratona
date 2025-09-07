#include <bits/stdc++.h>
using namespace std;

int sortp(pair<int,int> a, pair<int,int> b) {
    if (a.second < b.second) return 0;
    if (b.second < a.second) return 1;
    if (a.first > b.first) return 0;
    return 1;
}

void treat(string l) {
    vector<pair<int,int>> v;
    int ini = 0, size = 0;
    for (int i = 0; i < l.size(); i++) {
        size++;
        if (l[i] == ' ') {
            pair<int,int> p = {ini, size - 1};
            v.push_back(p);
            ini = i + 1;
            size = 0;
        }
    }
    if (size > 0) {
        pair<int,int> p = {ini, size};
        v.push_back(p);
    }
    sort(v.begin(), v.end(), sortp);
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = v[i].first; j < v[i].first + v[i].second; j++) {
            cout << l[j];
        }
        cout << " ";
    }
    for (int j = v[v.size() - 1].first; j < v[v.size() - 1].first + v[v.size() - 1].second; j++) {
        cout << l[j];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string line;
    cin >> n;
    getline(cin, line, '\n');
    for (int i = 0; i < n; i++) {
        getline(cin, line, '\n');
        treat(line);
    }
    return 0;
}