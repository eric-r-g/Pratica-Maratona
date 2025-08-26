#include <bits/stdc++.h>

using namespace std;

vector <int> cartas(10, 4);

int val_ajust(int entr){
    if (entr > 10) return 10;
    return entr;
}

int main(){
    int n; cin >> n;

    cartas.push_back(16);

    int joao = 0, maria = 0;
    
    int entr;
    cin >> entr; joao += val_ajust(entr); cartas[val_ajust(entr)]--;
    cin >> entr; joao += val_ajust(entr); cartas[val_ajust(entr)]--;
    cin >> entr; maria += val_ajust(entr); cartas[val_ajust(entr)]--;
    cin >> entr; maria += val_ajust(entr); cartas[val_ajust(entr)]--;

    for(int i = 0; i < n; ++i){
        cin >> entr;
        entr = val_ajust(entr);
        cartas[entr]--;
        joao += entr; maria += entr;
    }

    bool pos = false;
    for(int i = 1; i <= 10; ++i){
        if(!cartas[i]) continue;

        if(((joao + i > 23) && (maria + i <= 23))|| ((maria + i) == 23)){
            pos = true;
            cout << i << "\n";
            break;
        }
    }

    if (!pos) cout << "-1\n";
}