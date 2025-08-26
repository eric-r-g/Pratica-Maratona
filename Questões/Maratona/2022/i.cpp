#include <iostream>

using namespace std;

int main(){
    bool b = true;
    int entr;
    for(int i = 0; i < 8; ++i){
        cin >> entr;
        if(entr == 9) b = false;
    }

    if(b) cout << "S\n";
    else cout << "F\n";
}