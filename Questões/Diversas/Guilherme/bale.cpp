#include <bits/stdc++.h>
#define N_MAX 100000
using namespace std;

// Essa solução apenas resolve 70% dos casos de teste.

int res = 0;

void insertion_sort(vector<int> &vec) {
    int k;
    for (int i = 1; i < vec.size(); i++) {
        k = i;
        while (vec[k] < vec[k-1]) {
            int temp = vec[k];
            vec[k] = vec[k-1];
            vec[k-1] = temp;
            k--;
            res++;
        }
    }
}

void merge(vector<int> &vec, int ini, int meio, int fim) {
    int i, j, k;
    int n1 = meio - ini + 1;
    int n2 = fim - meio;
    vector<int> vec1, vec2;

    for (i = 0; i < n1; i++) {
        vec1.push_back(vec[ini + i]);
    }
    for (j = 0; j < n2; j++) {
        vec2.push_back(vec[meio + 1 + j]);
    }
    i = 0;
    j = 0;
    k = ini;
    while (i < n1 && j < n2) {
        if (vec1[i] <= vec2[j]) {
            vec[k] = vec1[i];
            i++;
        } else {
            res += (n1 - i);
            vec[k] = vec2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = vec1[i];
        k++; i++;
    }
    while (j < n2) {
        vec[k] = vec2[j];
        k++; j++;
    }
}

void merge_sort(vector<int> &vec, int ini, int fim) {
    if (ini < fim) {
        int meio = ini + (fim - ini) / 2;
        merge_sort(vec, ini, meio);
        merge_sort(vec, meio + 1, fim);
        merge(vec, ini, meio, fim);
    }
}

int main() {
    int n, input;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        vec.push_back(input);
    }
    //insertion_sort(vec);
    merge_sort(vec, 0, vec.size() - 1);
    cout << res << "\n";
    return 0;
}