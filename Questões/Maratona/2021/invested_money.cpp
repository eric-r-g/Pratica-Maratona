// não está funcional

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n;

    cin >> s >> n;
    int prox = 1;
    int entr;
    for(int i = 0; i < n; ++i){
        cin >> entr;
        if(!(entr % 30) || (prox && (entr % 30 > prox))) prox = entr % 30;
    }

    int mudanca;
    if (!prox){
        prox = 30;
        mudanca = 0;
    }
    else mudanca = (30 - prox) % 7;
    

    if ((s == "Sun" && mudanca == 6) or (s == "Mon" && mudanca == 5) or (s == "Tue" && mudanca == 4) or (s == "Wed" && mudanca == 3) or (s == "Thu" && mudanca == 2) or (s == "Fri" && mudanca == 1) or (s == "Sat" && mudanca == 0))
      cout << 30 - prox + 2;
    else if((s == "Sun" && mudanca == 0) or (s == "Mon" && mudanca == 6) or (s == "Tue" && mudanca == 5) or (s == "Wed" && mudanca == 4) or (s == "Thu" && mudanca == 3) or (s == "Fri" && mudanca == 2) or (s == "Sat" && mudanca == 1))
      cout << 30 - prox + 1;
    else cout << 30 - prox;
}