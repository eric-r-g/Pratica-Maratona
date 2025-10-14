#include <bits/stdc++.h>

using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  int as = a.size(), bs = b.size();
  int cont = 0;
	
  for(int i = 0; i <= as - bs; ++i){
    bool poss = true;
    for(int j = 0; j < bs; ++j){
      if (a[i + j] == b[j]){
	poss = false;
	break;
      }
    }
        
    if (poss) ++cont;
  }
    
  cout << cont << "\n";
}
