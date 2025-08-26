// não está funcional

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> dt;

int main() {
    ll n, d, t;
    ll soma = 0;
    bool possivel = true;
    cin >> n;
    dt.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> t >> d;
        dt[i] = {d, i, t, 0}; 
    }
    sort(dt.begin(), dt.end());
    for (ll i = 0; i < n; i++) {
        soma += dt[i][2];
        if (soma > dt[i][0]) {
            possivel = false;
            break;
        }
        dt[i][3] = soma;
    }
    if (possivel) {
        for (ll i = 0; i < n; i++) {
            int j = i - 1;
            while(j >= 0){
                if(dt[i][1] < dt[j][1] and (dt[j][0] >= dt[j][3] + dt[i][2])){
                    swap(dt[i], dt[j]);
                    dt[i][3] -= dt[j][2];
                    dt[j][3] += dt[i][2];
                } else break;
            }
        }

        for (ll i = 0; i < n-1; i++) {
               cout << dt[i][1]+1 << " ";
            }
        cout << dt[n-1][1]+1 << endl;
    } 
    else cout << "*" << endl;
    return 0;
}
