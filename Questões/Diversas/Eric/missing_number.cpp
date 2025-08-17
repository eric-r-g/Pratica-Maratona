#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 200001;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
 
    long long n;
    cin >> n;
 
    bool lista[MAXN] = {};
    int entr;
    int rep = n - 1;
    while(rep--){
        cin >> entr;
        lista[entr] = true;
    }
 
    for(int i = 1; i <= n; ++i){
        if(!lista[i]) cout << i << "\n";
    }
    return 0;
}