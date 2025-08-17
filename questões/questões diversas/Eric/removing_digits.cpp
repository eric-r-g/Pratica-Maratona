#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000001;
int num_min[MAXN];

int main(){
    int n; cin >> n;
    
    fill(num_min, num_min + n + 1, n + 1);
    num_min[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        int rt = i;
        while(rt > 0){
            int val = num_min[i - (rt % 10)] + 1;
            num_min[i] = min(val, num_min[i]);

            rt /= 10;
        }
    }

    cout << num_min[n];
}