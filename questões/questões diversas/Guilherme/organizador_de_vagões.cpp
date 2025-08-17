#include <bits/stdc++.h>
using namespace std;

int swaps = 0;

void insertion_sort(vector<int> v) {
    int p, temp;
    for (int i = 1; i < v.size(); i++) {
        p = i;
        while (p > 0 && v[p] < v[p - 1]) {
            swaps++;
            temp = v[p];
            v[p] = v[p - 1];
            v[p - 1] = temp;
            p--;
        }
    }
}

int main() {
    int n, l, inp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        swaps = 0;
        vector<int> vag;
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> inp;
            vag.push_back(inp);
        }
        insertion_sort(vag);
        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
    }
    return 0;
}
