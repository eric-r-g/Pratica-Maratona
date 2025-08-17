#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;

bool mat[1001][1001];
int num_rotas[1001][1001];

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            char entr; cin >> entr;
            mat[i][j] = (entr == '.') ? 1 : 0;
        }

    memset(num_rotas, 0, sizeof(num_rotas));
    num_rotas[n][n] = 1;

    for(int i = n; i > 0; --i)
        for(int j = n; j > 0; --j){
            if(mat[i][j]){
                
                if (num_rotas[i][j] > MOD) num_rotas[i][j] -= MOD;
                num_rotas[i - 1][j] += num_rotas[i][j];
                num_rotas[i][j - 1] += num_rotas[i][j];
                
            }
        }

    if(mat[1][1]) cout << num_rotas[1][1] << " ";
    else cout << 0 << " ";
}