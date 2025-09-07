#include <bits/stdc++.h>

using namespace std;

int main(){
    multiset <int> mp;
    vector <int> v;
    int n; cin >> n;
    int entr;
    
    for(int i = 0; i < n; ++i){
        cin >> entr;
        v.push_back(entr);
    }

    for(int i = n - 1; i >= 0; --i){
        auto it = mp.upper_bound(v[i]);
        if(it == mp.end()) mp.insert(v[i]);
        else{
            mp.erase(*it);
            mp.insert(v[i]);
        }
    }

    cout << ceil(log((double) mp.size()) / log(2));
}