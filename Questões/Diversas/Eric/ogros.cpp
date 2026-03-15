#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const ll MAXVAL = 1e9 + 1;
int main(){
    int n, m; 
    cin >> n >> m;

    vector <pll> intervalos;
    ll anter = 0, entr;
    for(int i = 0; i < n - 1; ++i){
        cin >> entr;
        intervalos.push_back(make_pair(anter, entr));
        anter = entr;
    }
    intervalos.push_back({anter, MAXVAL});

    vector <ll> premios(n, 0);
    for(int i = 0; i < n; ++i) cin >> premios[i];


    while(--m){
        cin >> entr;
        int i = 0, f = n - 1;
        while(i <= f){
            int med = i + (f - i) / 2;

            if (entr >= intervalos[med].first && entr < intervalos[med].second){
                cout << premios[med] << " ";
                break;
            }
            else if (intervalos[med].first > entr) f = med - 1;
            else i = med + 1;

        }

        
    }

    cin >> entr;
    int i = 0, f = n - 1;
    while(i <= f){
        int med = i + (f - i) / 2;

        if (intervalos[med].first <= entr && intervalos[med].second > entr){
            cout << premios[med] << "\n";
            break;
        }
        else if (intervalos[med].first > entr) f = med - 1;
        else i = med + 1;
    }
    return 0;
}