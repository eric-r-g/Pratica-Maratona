#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MOD = 1000000007;
const int MAXN = 100;
const int MAXK = 1000001;

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

    ll num_p[MAXK] = {};

    num_p[0] = 1;

    for(int i = 1; i <= x; ++i){
        for(int j = 0; j < n; ++j){
            int pos = i - moedas[j];
            if (pos < 0) continue;

            num_p[i] = (num_p[i] + num_p[pos]) % MOD;
        }
    }

    cout << num_p[x];
    
    return 0;
}