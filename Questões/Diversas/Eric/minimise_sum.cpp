#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n; 
    cin >> t;
    while(t--){
        cin >> n;
        int a, b;
        cin >> a >> b;
        if (a < b) cout << 2 * a << "\n";
        else cout << a + b << "\n";
        for(int i = 2; i < n; ++i) cin >> a;
    }

    return 0;
}