#include <bits/stdc++.h>

using namespace std;

vector <int> f_tree;
vector <int> arr;
int n;

// retorna a soma do intervalor 0, k
int prefixSum(int k){
    int soma = 0;
    
    for(int i = k; i > 0; i -= (i & -i))
        soma += f_tree[i];

    return soma;
}

// retorna a soma do intervalor ini, fim
int rangeSum(int ini, int fim){
    return prefixSum(fim) - prefixSum(ini - 1);
}

// atualizar a f_tree caso algum valor seja somado
void update(int k, int val){
    for(int i = k; i <= n; i += (i & -i))
        f_tree[i] += val;

    return;
}

void build(){
    for(int i = 1; i <= n; ++i){
        f_tree[i] += arr[i - 1];
        int j = i + (i & -i);
        if (j < n) 
            f_tree[j] += f_tree[i - 1];
    }

    return;
}

int main(){
    cin >> n;
    f_tree.resize(n + 1);
    arr.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    // codigo restante do problema
    return 0;
}
