#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n == 1 || n == 2) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int l;
    while (true) {
        cin >> l;
        if (l == 0) break;
        cout << fib(l) << "\n";
    }
    return 0;
}