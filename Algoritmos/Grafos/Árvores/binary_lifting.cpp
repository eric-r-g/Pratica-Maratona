#include <bits/stdc++.h>

using namespace std;
const int MAXN = 20010, MAXLOG = 30;
int prox[MAXLOG + 1][MAXN];

int n;

int proximo(int ini, int k){
    for (int i = 0; i <= MAXLOG; i++) {
      if (k & (1 << i)) ini = prox[i][ini];
    }

    return ini;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; +i)
        cin >> prox[0][1];

    for(int x = 1; x <= 30; ++x)
        for(int i = 1; i <= n; ++i)
            prox[x][i] = prox[x - 1][prox[x - 1][i]];
}