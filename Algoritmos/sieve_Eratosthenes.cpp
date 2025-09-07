#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

//Cálculo de todos os primos no intervalo [1, n]
int spf[MAX];
void crivo(int n){
    for(int i = 1 ; i <= n ; i++) spf[i] = 1;

    for(int i = 2 ; i <= n ; i++) if(spf[i] == 1)
        for(int j = i ; j <= n ; j+=i) spf[j] = i;
}

int main(){    
    int n; cin >> n;
    crivo(n);
    for(int i = 2 ; i <= n ; i++){
        if(spf[i] == i) cout << i << "eh primo" << endl;
    } 
}
