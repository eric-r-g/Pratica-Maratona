#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b;
    while(true){
        cin >> n >> b;

        if(!n) break;
        vector <int> v;

        int entr;
        for(int i = 0; i < b; ++i){
            cin >> entr;
            v.push_back(entr);

        }

        bool poss[91] = {false};
        for(int i = 0; i < b; ++i){
            for(int j = i; j < b; ++j){
                int val = abs(v[i] - v[j]);
                if (val <= n) poss[val] = true;
            }
        }

        int eh_pos = true;
        for(int j = 0; j <= n; ++j){
            if (!poss[j]){ 
                eh_pos = false; 
                break;
            }
        }
        if(eh_pos) cout << "Y\n";
        else cout << "N\n";

    }
}