#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(){
    _
    int n, c;
    cin >> n >> c;

    map <string, int> m;
    vector <string> v;

    string entr;
    for(int i = 0; i < n; ++i){
        cin >> entr;

        set <string> adicionados;

        for(int j = 0; j < v.size(); ++j){
            string x = "";
            bool poss = true;

            

            for(int k = 0; k < c; ++k){
                if(v[j][k] == entr[k] && entr[k] == '*'){ // dois * na mesma pos
                    poss = false;
                    break;
                } else if (v[j][k] == entr[k] || v[j][k] == '*'){ // sao iguais ou * no v[i]
                    x += entr[k];
                } else if (entr[k] == '*'){ // * no entr
                    x += v[j][k];
                } else { // sao distintos
                    poss = false;
                    break;
                }
            }

            if (poss && adicionados.find(x) == adicionados.end()){
                if(m.find(x) != m.end()) m[x]++;
                else m[x] = 2;
                adicionados.insert(x);
            }
        }
        v.push_back(entr);
    }

    int maior = 0;
    string x = "";
    for(const auto & par : m){


        if(par.second > maior){
            x = par.first;
            maior = par.second;
        } else if (par.second == maior && par.first < x){
            x = par.first;
        }
    }

    cout << x << " " << maior << endl;
}