#include <bits/stdc++.h>
 
using namespace std;
const int MAXC = 1000001;
const int MAXN = 100;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n, x;
    cin >> n >> x;
 
    int moedas[MAXN];
    for(int i = 0; i < n; ++i){
        cin >> moedas[i];
    }
 
    long long min_moedas[MAXC];
 
    for(int i = 1; i <= x; ++i){
        min_moedas[i] = INT32_MAX;
    }
 
    min_moedas[0] = 0;
 
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < n; ++j){
            int val = i + moedas[j];
            if(val <= x && min_moedas[val] > min_moedas[i] + 1){
                min_moedas[val] = min_moedas[i] + 1;
            }
        }
    }
 
    if(min_moedas[x] != INT32_MAX)
        cout << min_moedas[x] << "\n";
    else cout << -1;
    return 0;
}