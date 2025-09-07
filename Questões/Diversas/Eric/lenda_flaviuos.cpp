#include <bits/stdc++.h>

using namespace std;

int main(){
    int ct; 
    cin >> ct;
    int n, k;
    for(int rep = 1; rep <= ct; ++rep){
        cin >> n >> k;
        int val = 0;
        for(int i = 2; i <= n; ++i){
            val = (val + k) % i;
        }

        cout << "Case " << rep << ": " << val + 1 << "\n";
    }
}