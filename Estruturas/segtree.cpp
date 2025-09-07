#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int seg[4 * MAXN];
int v[MAXN];

void build(int i, int l, int r){
    if (l == r){
        seg[i] = v[l];
    } else {
        int mid = l + (r - l) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

void update(int i, int l, int r, int pos, int k) {
    if (l == r) {
        seg[i] = k; 
        v[pos] = k;  
    } else {
        int mid = l + ((r - l) >> 1);
        if (pos <= mid) {
            update(2 * i, l, mid, pos, k);
        } else {
            update(2 * i + 1, mid + 1, r, pos, k);
        }
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

int query(int node, int tl, int tr, int l, int r){

    if(r<tl or l>tr) return 0;
    if(l<=tl and r>=tr) return seg[node];

    int mid = tl + ((tl - tr) >> 1);
    return query(2*node, tl, mid, l, r)+query(2*node, mid+1, tr, l, r);
}

int main(){
    int n; cin >> n;
}