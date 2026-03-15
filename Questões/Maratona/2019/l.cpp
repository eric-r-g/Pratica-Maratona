#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long n, cont = 0, saida = 1;
    cin >> n;
    while (n){ 
        if(n & 1) saida *= 2;
        n >>= 1;
    }
    cout << saida << '\n';
    return 0;
} 


