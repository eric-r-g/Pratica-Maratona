#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

struct query {
    int l;
    int r;
    int ind;
};

// definimos baseado no maior N possivel
const int sz = 317;

// funciona bem para a maioria dos casos
void mos_algorithm(vector <query>& qs, int n){

    sort (qs.begin(), qs.end(), [](const query &a, const query &b){
        int blocoA = (a.l - 1) / sz;
        int blocoB = (b.l - 1) / sz;

        if (blocoA != blocoB) return blocoA < blocoB;
        
        if(blocoA & 1) return a.r > b.r;
        return a.r < b.r;
    });
}

// valor a ser modificado
int acum = 0;

// aumenta o intervalo
void add(int pos, vector <int>& v){

}

// diminui o intervalo
void sub(int pos, vector <int>& v){

}

int main(){
    int n, q; cin >> n >> q;

    vector <int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    vector <query> qs(q);
    for(int i = 0; i < q; i++){
        cin >> qs[i].l >> qs[i].r; 
        qs[i].ind = i;
    }

    mos_algorithm(qs, n);

    vector <int> saida(q);

    int l = qs[0].l;
    int r = qs[0].r;
    for(int i = l; i <= r; i++)
        add(i, v);

    for(const query& qx : qs){
        while(l > qx.l){
            l--;
            add(l, v);
        }
        while(r < qx.r){
            r++;
            add(r, v);
        }
        while(l < qx.l){
            sub(l, v);
            l++;
        }
        while(r > qx.r){
            sub(r, v);
            r--;
        }

        saida[qx.ind] = acum;
    }

    for(int x : saida) cout << x << " ";
    cout << "\n";
}