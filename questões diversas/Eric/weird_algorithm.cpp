#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
 
    long long n; cin >> n;
    cout << n << " ";
 
    while(n != 1){
        if(n % 2) n = 3 * n + 1;
        else n /= 2;
        cout << n << " ";
    }
    return 0;
}