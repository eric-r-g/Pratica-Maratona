#include <bits/stdc++.h>

using namespace std;

int main(){
    int e, c, r; 
    cin >> e >> c >> r;

    vector <int> atv_can;

    int entr;
    for(int i = 0; i < c; ++i){
        cin >> entr;
        atv_can.push_back(entr);
    }

    for(int i = 0; i < r; ++i){
        cin >> entr;
        e += entr;
    }

    int i = 0;
    while(i < atv_can.size() && e >= atv_can[i]){
        e -= atv_can[i];
        i++;
        r++;
    }

    cout << r << "\n";
}