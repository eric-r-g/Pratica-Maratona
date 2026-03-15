#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

int n, k, t;

struct cmp {
    bool operator()(pll p1, pll p2) const {
        return p1.first + k - t + p1.second < p2.first + k - (t - p2.second);
    }
};


int main(){
    cin >> n >> k;

    vector <ll> v(n, 0), menor_e(n, 0), menor_d(n, 0);
    ll entr; 
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    ll menor = v[0];
    for(int i = 0; i < n; ++i){
        if (v[i] < menor) menor = v[i];
        menor_e[i] = menor;
    }

    menor = v[n - 1];
    for(int i = n - 1; i >= 0; --i){
        if (v[i] < menor) menor = v[i];
        menor_d[i] = menor;
    }
    


    set <pll, cmp> janela_k;
    vector <ll> menores(n, 0);

    t = 0;
    for(; t < n; ++t){
        bool oper_inicial = false;
        if(janela_k.size() == k){
            janela_k.erase({v[t - k], t - k});
            menores[t] = menor_e[t - k];
            oper_inicial = true;
        }
        janela_k.insert({v[t], t});
        if(oper_inicial){
            pll par = *janela_k.begin();
            menores[t] = min(menores[t], par.first + k - (t - par.second));
        } else {
            pll par = *janela_k.begin();
            menores[t] = par.first + k - (t - par.second);
        }

        if(t < n - 1) menores[t] = min(menores[t], menor_d[t + 1]);
    }

    long long maior = menores[0];
    for(int i = 1; i < n; ++i){
        if (menores[i] > maior) maior = menores[i];
    }

    cout << maior << "\n";
}