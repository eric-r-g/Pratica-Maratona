#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1000002;

int main(){
    int n; cin >> n;

    ll baloes[MAXN] = {}, entr;
    for(int i = 0; i < n; ++i){
        cin >> entr;
        if (baloes[entr + 1]){
            baloes[entr + 1]--;
            baloes[entr]++;
        } else {
            baloes[entr]++;
        }
    }

    int soma = 0;
    for(int i = 1; i < MAXN - 1; ++i) soma += baloes[i];
    cout << soma;
}