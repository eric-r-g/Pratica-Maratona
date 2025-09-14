#include <bits/stdc++.h>

using namespace std;

// constantes e variaveis padroes

vector <int> lis;
vector <int> nums;
int n;

// DP n²
// mais simples de implementar (inclusive para encontrar a lista real, não só o tamanho)

void lis_n2(){
    lis.resize(n);
    lis[n - 1] = 1;

    for(int i = n - 2; i >= 0; --i){
        lis[i] = 1;
        for(int j = i + 1; j < n; ++j){
            if(nums[j] > nums[i]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    int maior = 0;
    for(int i = 0; i < n; ++i) maior = max(maior, lis[i]);

    cout << maior << "\n";
}

// DP n log n
// mais sdificil de implementar, porém mais rapida 

void lis_nlogn(){
    vector <int> v;
    v.push_back(nums[0]);

    for(int i = 1; i < n; ++i){
        if(nums[i] > v[v.size() - 1]) v.push_back(nums[i]);
        else {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            *it = nums[i];
        }
    }

    cout << v.size() << "\n";
}


int main(){
    cin >> n;

    nums.resize(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    

    
    return 0;
}