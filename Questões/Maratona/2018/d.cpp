#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int cont = 0;
  while(n--){
    int entr; cin >> entr;
    if (entr != 1) cont++;
  }
  
  cout << cont << "\n";
  return 0;
}
