#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 200001;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
 
    string entr;
    cin >> entr;
 
    char atual = entr[0];
    int max = 0, tam = 1;
    for(int i = 1; i < entr.size(); ++i){
        if(atual == entr[i]) tam++;
        else {
            if(tam > max) max = tam;
            tam = 1;
            atual = entr[i];
        }
    }
    if(tam > max) max = tam;
    cout << max << "\n";
    
    return 0;
}