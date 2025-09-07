#include <bits/stdc++.h> 

using namespace std;

int main(){
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    while (xi != 0){
        if (xi == xf && yi == yf) cout << 0 << "\n";
        else if (xi == xf || yi == yf || (xi + yi == xf + yf) || (xi - yi == xf - yf)) cout << 1 << "\n";
        else cout << 2 << "\n";

        cin >> xi >> yi >> xf >> yf;
    }
}