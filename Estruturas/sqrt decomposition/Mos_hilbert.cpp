#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

struct query {
    int l;
    int r;
    int ind;
};

// utilizar somente em caso de TLE no Mo's tradicional

const int LIM = 21;

// calcula o valor de uma coordenada na ordem hilbert
int hbo(int x, int y, int pow, int rot = 0){
    if (pow == 0) return 0;

    int hpow = 1LL << (pow - 1);

    int seg;
    if(x < hpow){
        if (y < hpow) seg = 0;
        else seg = 3;
    } else {
        if (y < hpow) seg = 1;
        else seg = 2;
    }
    
    seg = (seg + rot) & 3;

    int nx = x & (x ^ hpow);
    int ny = y & (y ^ hpow);

    int nrot;
    if(seg == 0) nrot = (rot + 3) & 3;
    else if(seg == 3) nrot = (rot + 1) & 3;
    else nrot = rot;

    int subSquare = 1LL <<(2 * pow - 2);
    int ans = seg * subSquare;

    int add = hbo(nx, ny, pow - 1, nrot);

    if(seg == 1 || seg == 2) ans += add;
    else ans += subSquare - add - 1;

    return ans;
}

// ordenação um pouco melhor
void mos_hilbert(vector <query>& qs){
    int q = qs.size();
    vector <int> hilb_val(q);

    for(int i = 0; i < q; i++){
        hilb_val[i] = hbo(qs[i].l, qs[i].r, LIM);
    }

    sort(qs.begin(), qs.end(), [&hilb_val](const query &a, const query &b){
        int pa = a.ind, pb = b.ind;
        
        return hilb_val[pa] < hilb_val[pb];
    });
}