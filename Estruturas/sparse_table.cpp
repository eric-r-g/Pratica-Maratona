#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5;
const int MAXLOG = 30;

int menor[MAXN][MAXLOG + 1];

int n;

int flog(int x) { // Calcula a parte inteira do log2 de x em O(1) ( para int )
	return 31 - __builtin_clz(x);
}

int query(int l, int r) {
	int k = flog(r - l + 1);

	return min(menor[l][k], menor[r - (1<<k) + 1][k]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> menor[i][0];
    }


    for(int j = 1; j <= MAXLOG; ++j){
        for(int i = 0; i < n; ++i){
            if (i + (1<<j) - 1 > n) break;
            menor[i][j] = min(menor[i][j-1], menor[i + (1<<(j-1))][j-1]);
        }
    }

    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;

        cout << query(a, b);
    }
    return 0;
}