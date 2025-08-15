#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
 
const ui MOD = 1000000007;
const int MAXN = 100;
const int MAXK = 1000001;
ui num_p[MAXK] = {};

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n, x;
    cin >> n >> x;

    
    int moedas[MAXN];


    for(int i = 0; i < n; ++i){
        cin >> moedas[i];
    }


    num_p[0] = 1;

    for(int j = 0; j < n; ++j){
        for(int i = 1; i <= x; ++i){
            int pos = i - moedas[j];
            if(pos < 0) continue;

            num_p[i] += num_p[pos];
            if(num_p[i] >= MOD) num_p[i] -= MOD;
        }
    }

    cout << num_p[x] << "\n";

    return 0;
}