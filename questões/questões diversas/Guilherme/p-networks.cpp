#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> s) {
    bool ord;
    int ind = s.size() - 1, temp, swaps = 0;
    vector<int> res;
    do {
        ord = true;
        for (int i = 0; i < ind; i++) {
            if (s[i] > s[i+1]) {
                swaps++;
                ord = false;
                res.push_back(i + 1);
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
        ind--;
    } while (ord == false);
    cout << swaps;
        if (swaps > 0) {
        for (int i = 0; i < res.size(); i++) {
            cout << " " << res[i];
        }
    }
    cout << endl;
}

int main() {
    int n, inp;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int b = 0;
        vector<int> s(n);
        vector<bool> p(n);
        for (int i = 0; i < n; i++) {
            cin >> inp;
            s[i] = inp;;
            p[inp-1] = true;
        }
        for (bool v : p) {
            if (v == false) {
                cout << "No solution" << endl;
                b = 1;
                break;
            }
        }
        if (b == 1) continue;
        bubble_sort(s);
    }
    return 0;
}
