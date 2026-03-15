#include <bits/stdc++.h>
using namespace std;

vector <vector <pair <int, int>>> v;

void insere_val(int pos, int val){
 	bool a = true;;
	for(int i = 0; i < v[pos].size(); ++i){
  	if (v[pos][i].first == val){ 
    	v[pos][i].second++;
    	a = false;
    }
  }
  
  if (a) v[pos].push_back({val, 1});
}

int main() {
	int n, k; 
    cin >> n >> k;
    v = vector <vector <pair <int, int>>> (n + 1, vector <pair <int, int>>());
  
    char entr;
    for (int i = 1; i <= n; ++i) 
  	    for (int j = 0; j < 4; ++j){
    	    cin >> entr;
            if (entr == 'A') insere_val(i, 1);
            else if (entr == 'D') insere_val(i, 10);
            else if (entr == 'Q') insere_val(i, 11);
            else if (entr == 'J') insere_val(i, 12);
            else if (entr == 'K') insere_val(i, 13);
            else insere_val(i, entr - '0');
        }

    return 0;
}