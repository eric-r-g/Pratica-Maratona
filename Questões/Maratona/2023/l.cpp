#include <bits/stdc++.h>

using namespace std;



int main(){
    string s; int k;
    cin >> s >> k;
    vector <string> vs (k, "");

    int i = 0;
    for(int j = 0; j < s.size(); ++j){
        vs[i] += s[j];
        i++;
        if(i == k) i = 0;
    }

    for(int j = 0; j < k; ++j) sort(vs[j].begin(), vs[j].end());

    string saida = "";
    i = 0;
    int pos = 0;
    for(int j = 0; j < s.size(); ++j){
        saida += vs[i][pos];
        i++;
        if(i == k) {
            i = 0;
            pos++;
        }
    }

    cout << saida << "\n";
}