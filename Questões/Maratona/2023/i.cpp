#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, entr; 
    cin >> n;

    long long total = 0;
    int impar = 0, par = 0;

    while(n--){
        cin >> entr;
        if(entr){
            int temp = par + 1;
            par = impar;
            impar = temp;
            total += impar;
        } else {
            par++;
            total += impar;
        }
    }

    cout << total << "\n";
}