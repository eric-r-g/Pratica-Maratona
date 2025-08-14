#include <bits/stdc++.h>
#define N_MAX 100000
using namespace std;

int main() {
    int n, x, nums[N_MAX], p = 0, soma = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums[p] = x;
        if (x != 0) p++;
        else if (nums[p] == 0) p--;
    }
    for (int i = 0; i < p; i++) {
        soma += nums[i];
    }
    cout << soma << endl;
    return 0;
}