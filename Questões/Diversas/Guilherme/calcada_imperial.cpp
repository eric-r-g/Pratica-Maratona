#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ult, seq, maior = 1;
    vector<bool> nums(500);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        nums[v[i]-1] = true;
    }
    for (int i = 0; i < 500; i++) {
        if (!nums[i]) continue;
        for (int j = i+1; j < 500; j++) {
            if (!nums[j]) continue;
            seq = 0;
            ult = 0;
            for (int k = 0; k < n; k++) {
                if ((v[k] == i+1 || v[k] == j+1) && (v[k] != ult)) {
                    seq++;
                    ult = v[k];
                }
            }
            if (seq > maior) maior = seq;
        }
    }
    cout << maior << endl;
    return 0;
}
