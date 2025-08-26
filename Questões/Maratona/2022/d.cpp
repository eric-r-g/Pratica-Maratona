#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int i, j; cin >> i >> j;

    for(int rep = 0; rep < 20; ++rep){
        if (i & (1 << rep) || j & (1 << rep)){
            cout << n - rep - 1 << endl;
            break;
        }
    }
}