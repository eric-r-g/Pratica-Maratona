#include <bits/stdc++.h>
using namespace std;

int main() {
    int maior = 1;
    int conseq = 1;
    string seq;
    cin >> seq;
    for (int i = 1; i < seq.size(); i++) {
        if (seq[i] == seq[i-1]) conseq++;
        else {
            if (conseq > maior) maior = conseq;
            conseq = 1;
        }
    }
    if (conseq > maior) maior = conseq;
    conseq = 0;
    cout << maior << "\n";
    return 0;
}
