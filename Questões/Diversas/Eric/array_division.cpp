#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector <ll> v(n, 0);

    ll ini = 0, fim = 0;
    for(int i = 0; i < n; ++i){ 
        cin >> v[i];
        fim += v[i];
        if (v[i] > ini) ini = v[i];
    }

    ll menor = 1e15 + 1;
    while(ini <= fim){
        ll med = ini + (fim - ini) / 2;
        int cont = 1;
        long long soma = 0;
        for(int i = 0; i < n; ++i){
            if (soma + v[i] <= med) soma += v[i];
            else {
                cont++;
                soma = v[i];
            }
        }

        if (cont <= k){
            menor = med;
            fim = med - 1;
        } else ini = med + 1;
    }

    cout << menor << "\n";

    return 0;
}