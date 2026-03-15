#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair <ll, pll> plpll;

int main(){
    int t; cin >> t;
    ll n, k;

    while(t--){
        cin >> n >> k;
        vector <plpll> v;
        ll li, ri, real;

        for(int i = 0; i < n; ++i){
            plpll p;
            cin >> li >> ri >> real;
            p.first = real;
            p.second.first = li;
            p.second.second = ri;
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        long long val_final = -1, k_atual, k_maior = k;
        while(val_final != k_maior){
            val_final = k_maior;
            k_atual = k_maior;
            int i = 0, f = n - 1;
            while(i <= f){
                int med = i + (f - i) / 2;
                plpll p = v[med];
                pll inter = p.second;
                if(inter.first <= k_atual && inter.second >= k_atual){
                    if(p.first > k_maior) k_maior = p.first;
                    i = med + 1;
                } else if (inter.first > k) f = med - 1;
                else i = med + 1;
            }
        }

        cout << val_final << "\n";
    }
    return 0;
}
