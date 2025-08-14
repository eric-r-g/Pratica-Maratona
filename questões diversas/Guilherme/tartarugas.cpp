#include <bits/stdc++.h>
using namespace std;

int menor_tempo(int px, int py, vector<int> x, vector<int> y, vector<char> &c, vector<int> rest) {
    int dist;
    int val, min = INT_MAX;
    for (int i = 0; i < rest.size(); i++) {
        int px2, py2;
        vector<int> x2 = x, y2 = y;
        if (c[rest[i]] == 'D' && px - 4 > x[rest[i]]) dist = ceil((double) (px - x[rest[i]]) / 3.0);
        else dist = abs(px - x[rest[i]]);
        if (c[rest[i]] == 'C' && py - 4 > y[rest[i]]) dist += ceil((double) (py - y[rest[i]]) / 3.0);
        else dist += abs(py - y[rest[i]]);
        for (int j = 0; j < rest.size(); j++) {
            if (c[rest[j]] == 'C') y2[rest[j]] += dist;
            else x2[rest[j]] += dist;
        }
        px2 = x2[rest[i]];
        py2 = y2[rest[i]];
        vector<int> rest2 = rest;
        rest2.erase(rest2.begin() + i);
        val = dist + menor_tempo(px2, py2, x2, y2, c, rest2);
        if (val < min) min = val;
    }
    if (rest.size() > 0) return min;
    return 0;
}

int main() {
    int px, py;
    vector<int> x(3), y(3), rest = {0, 1, 2};
    vector<char> c(3);
    while(true) {
        cin >> px >> py;
        if (px == 0 && py == 0) break;
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i] >> c[i];
        }
        cout << menor_tempo(px, py, x, y, c, rest) << endl;
    }
    return 0;
}
