#include <bits/stdc++.h>


using namespace std;

int main(){
    unsigned long long a, b;
    while(cin >> a >> b){
        unsigned long long saida = 0;

        for(int i = 0; i < 32; ++i) saida |= (a & (1 << i)) ^ (b & (1 << i)) ;
        cout << saida << "\n";
    }
}