#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int maior = 0;
        int entr;
        for(int i = 0; i < n; ++i){
            cin >> entr; if (entr > maior) maior = entr;
        }
        cout << maior << "\n";
    }
}