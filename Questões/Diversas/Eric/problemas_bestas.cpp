#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        bool crescen = true;
        int ant, entr;
        cin >> ant;
        int maior = ant;
        for(int i = 1; i < k; ++i){
            cin >> entr;
            if (maior < entr) maior = entr;
            if (ant >= entr) crescen = false;
            ant = entr;
        }

        if (crescen) cout << n - maior + 1 << "\n";
        else cout << 1 << "\n";
    }
}